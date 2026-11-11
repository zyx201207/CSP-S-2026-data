#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,a[N],fa[N];
vector<int> vis(N);
inline int find(int x){
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vis.clear();
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			a[i]=1;fa[i]=i;
			int x=find(u),y=find(v);
			fa[y]=x;a[x]+=a[y];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(vis[a[i]]==0){
				ans++;
				vis[a[i]]=1;
			}
		}
		if(ans>1)cout<<1<<"\n";
		else cout<<2<<"\n";
	}
	return 0;
}