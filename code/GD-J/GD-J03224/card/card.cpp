#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],siz[N],ans[M],nxt[M];
bool vis[N];
vector<int>e[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i;i--){
		if(nxt[a[i]])e[nxt[a[i]]].emplace_back(i);
		else vis[i]=1;nxt[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		siz[i]=1;if(vis[i-1])siz[i]+=siz[i-1];
		for(int j:e[i])siz[i]+=siz[j];
		if(vis[i])ans[a[i]]=siz[i];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
