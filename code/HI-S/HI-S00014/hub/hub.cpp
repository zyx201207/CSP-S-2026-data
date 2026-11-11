#include<bits/stdc++.h>
using namespace std;
int u[10000000],v[1000000];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,n,k,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<n;j++){
			cin>>u[i]>>v[i];
		}	 
		cout<<(n*n-k-n+1)/2+1;
	} 
	return 0;
} 
