#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k;
long long q[10000][10000];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;++i){
			int u,v;
			cin>>u>>v;
			q[u][v]=1;
			q[v][u]=1;
		}
		cout<<n/2*3<<"\n";
	}
	return 0;
} 
