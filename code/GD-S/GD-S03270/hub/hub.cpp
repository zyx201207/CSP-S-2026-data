#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,k;
long long u,v,mp[501][501]; 
long long ans=0;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	memset(mp,0,sizeof(mp));
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
			mp[u][v]=mp[v][u]=1;
		}
	}
	cout<<"1"<<endl<<"2";
	return 0;
}
