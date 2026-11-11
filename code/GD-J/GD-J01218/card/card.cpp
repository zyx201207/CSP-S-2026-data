#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int maxn=2e5+5;
int a[maxn],n,m,ans[maxn],vis[maxn],p[maxn];

inline void solve(int l){
	for(int i=0;i<=max(n,m)+15;++i) vis[i]=p[i]=0;
	for(int i=l;i<=n;++i){
		if(vis[a[i]]==0) {
			vis[a[i]]=1;
			p[a[i]]=i;
		}
		else if(vis[a[i]]==1){
			for(int j=p[a[i]];j<i;++j){
				vis[a[j]]=0;
			}
			vis[a[i]]=1;
		}
	}
	for(int i=1;i<=m;++i){
		if(vis[i]==1) ans[i]++;
	}
}

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		solve(i);
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
	return 0; 
}
