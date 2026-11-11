#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int C,T,n,d,x[N],nxt[N],pre[N],f[N];
inline void solve(){
	for(int i=1;i<=n;i++) nxt[i]=pre[i]=f[i]=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		int j=nxt[i-1]+1;
		while(j<=n&&x[j]-x[i]<=d) j++;
		nxt[i]=j-1;
	}
	pre[n+1]=n+1;
	for(int i=n;i>=1;i--){
		int j=pre[i+1]-1;
		while(j>=1&&x[i]-x[j]<=d) j--;
		pre[i]=j+1;
	}
	if(C<=10){
		int ans=0;
		for(int v=2;v<=n;v++){
			int p=v;f[v]=1;
			for(int u=v-1;u>=1;u--){
				if(nxt[u]<p) p=u+1;
				if(x[u+1]-x[u]>d) break;
				f[u]=nxt[u]>p+1&&p!=v?3:nxt[u]==p?f[p]:min(f[p]+f[p+1],3ll);
				ans+=f[u]==2;
			}
		}
		cout<<ans<<'\n';
		return;
	}
	if(13<=C&&C<=18){
		int ans=0;
		for(int v=2;v<=n;v++){
			f[v]=1;
			for(int p=v,u=pre[v];u!=1;p=u,u=pre[u]){
				int lim=f[p]+f[p+1]<3?p+1:f[p]<3?p:p-1;
				if(lim==p-1) break;
				int r=upper_bound(nxt+u,nxt+n+1,lim)-nxt-1;
				int l=lower_bound(nxt+u,nxt+n+1,f[p]==1?p+1:p)-nxt;
				ans+=max(r-l,0ll);
				f[u]=nxt[u]>p+1&&p!=v?3:nxt[u]==p?f[p]:min(f[p]+f[p+1],3ll);
				if(u+1<p) f[u+1]=nxt[u+1]>p+1&&p!=v?3:nxt[u+1]==p?f[p]:min(f[p]+f[p+1],3ll);
			}
		}
		clog<<ans<<'\n';
		return;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--) solve();
	return 0;
}
/*
假如先忽略>d的间隔 
每次贪心尽量飞，显然是一个最短路径
从DP的角度来说，显然每个点下一次能保证走最短路的点是一个区间
一个点不被ban(方案<=2)的充要条件为：
1.落脚区间不存在ban
2.要么区间大小为1，要么区间大小为2且两个落脚点方案唯一

感性理解，随着v的右移，每个点的区间不会变大，
因为被淘汰的起点不会在更长的路径中追上优胜的起点

固定v，dis(u,v)随u单调，
dis相同的u左端点相同(第一个dis-1的u)，右端点不降，
所以dis相同的u中方案数也不降 

气笑了，又不会！ 
*/
