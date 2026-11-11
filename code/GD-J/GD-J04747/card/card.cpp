#include<bits/stdc++.h>
using namespace std;
int n,m,tong[300002],nu[500001];
bool sf[300002];
void aa(int yy){
	for(int i=0;i<=300000;i++)sf[i]=0;
	stack<int>bb;
	for(int i=yy;i<=n;i++){
		if(sf[nu[i]]==1){
			while((!bb.empty())&&(sf[nu[i]])){
				sf[bb.top()]=0;
				bb.pop();
			}
			sf[nu[i]]=1;
			bb.push(nu[i]);
		}else{
			sf[nu[i]]=1;
			bb.push(nu[i]);
		}
	}
	while(!bb.empty()){
		tong[bb.top()]++;
		bb.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nu[i];
	}
	for(int i=1;i<=n;i++){
		aa(i);
	}
	for(int i=1;i<=m;i++)cout<<tong[i]<<" ";
	
	return 0;
} 

