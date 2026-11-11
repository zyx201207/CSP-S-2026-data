#include<bits/stdc++.h>
using namespace std;
stack <int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10000]={};
	int b[10000]={};
	for(int i=0;i<n;i++){
		cin>>a[n];
	}
	for(int i=0;i<n;i++){
		int c[10000]={0};
		for(int j=i;j<n;j++){	
			if(c[a[j]]==0){
				c[a[j]]++;
				s.push(a[j]);
			}else{
				while(s.top()!=a[j]){
					s.pop();
				}
			}
		}
		while(s.empty()!=1){
			b[s.top()]++;
			s.pop();
		}
		cout<<endl;
	}
	for(int i=0;i<m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
