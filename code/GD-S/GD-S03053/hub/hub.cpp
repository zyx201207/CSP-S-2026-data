#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int a[N],n,c,t,k,dist[10010][10010];
int f[N];
int find(int x){
	if(f[x]==x) return x;
	else return find(f[x]);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<+n;i++) f[i]=i;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			dist[u][v]=dist[v][u]=1;
			f[u]=find(v);
		}
	}
	return 0;
}
