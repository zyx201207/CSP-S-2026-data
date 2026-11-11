#include<bits/stdc++.h>
using namespace std;
stack <long long> e;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long nn=n;
	long long a[n+1]={};
	long long f[m+1]={};
	long long cn[m+1]={};
	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	while(nn--){
		for(long long i=n-nn+1;i<=n;i++){
		f[m+1]={};
			if(f[a[i]]==0){
				e.push(a[i]);
				f[a[i]]=1;
			}
			else{
				while(e.top()!=a[i]){
					e.pop();	
				}
			}
			while(!e.empty()){
				cn[e.top()]++;
				e.pop();
			}
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<cn[i]<<" ";
	}
	return 0;
}
