#include<bits/stdc++.h>
using namespace std;
stack<int> a;
int num[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int sd=0;sd<n;sd++){
		int b[m+1]={0};
		for(int i=sd;i<n;i++){
			int u;
			u=s[i];
			b[u]++;
			if(b[u]>1){
				while(a.top()!=u){
					a.pop();
				}
				a.pop();
			}
			a.push(u);
		}
		while(!a.empty()){
			int k=a.top();
			num[k]++;
			a.pop();
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	
	return 0;
}
