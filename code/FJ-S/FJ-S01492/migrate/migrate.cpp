#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
const int inf=0x3f3f3f3f,N=2000005;
const ll INF=0x3f3f3f3f3f3f3f3f;
int C,n,pre[N],nxt[N],cl[N],cr[N];
ll d,p[N];
void solve(){
	fill(cl,cl+n+2,0),fill(cr,cr+n+2,0);
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>p[i];
	p[0]=p[1]-d,p[n+1]=p[n]+d;
	for(int i=1;i<=n;i++){
		nxt[i]=upper_bound(p,p+n+2,p[i]+d)-p-1;
		pre[i]=lower_bound(p,p+n+2,p[i]-d)-p;
		if(nxt[i]==i) nxt[i]=n+1;
		if(pre[i]==i) pre[i]=0;
		// debug("! %d %d %d\n",i,pre[i],nxt[i]);
	}
	pre[0]=nxt[0]=0,pre[n+1]=nxt[n+1]=n+1;
	fill(cl+1,cl+n+1,1),fill(cr+1,cr+n+1,1);
	for(int i=1;i<=n;i++) cl[nxt[i]]++,cr[pre[i]]++;
	ll ans=0;
	for(int i=1;i<=n;i++)
		if(pre[i]&&nxt[pre[i]]==i) cl[i]+=cl[pre[i]]-1;
	for(int i=n;i;i--)
		if(nxt[i]&&pre[nxt[i]]==i) cr[i]+=cr[nxt[i]]-1;
	for(int i=2;i<=n;i++){
		int x=pre[pre[i]];
		if(x&&pre[i]+1==nxt[x]&&i==nxt[nxt[x]])
			ans+=1LL*(cl[x]-1)*(cr[i]-1);
			// debug("+ %d %d %d*%d\n",x,i,cl[x],cr[i]);
	}
	for(int i=2;i<=n;i++){
		int x=pre[pre[i]];
		if(x&&pre[i]+1==nxt[x]&&i!=nxt[nxt[x]]&&p[nxt[x]]+d>=p[i]){
			ans+=cl[x]-1;
			// debug("+A %d %d %d\n",i,x,cl[x]-1);
		}
	}
	for(int i=1;i<n;i++){
		int x=nxt[nxt[i]];
		if(x<=n&&nxt[i]-1==pre[x]&&i!=pre[pre[x]]&&p[pre[x]]-d<=p[i]){
			ans+=cr[x]-1;
			// debug("+B %d %d %d\n",i,x,cr[x]-1);
		}
	}
	// debug("%lld\n",ans);
	for(int i=1;i+3<=n;i++){
		int p1=lower_bound(p,p+n+2,p[i+2]-d)-p,
			p2=min((int)(lower_bound(p,p+n+2,p[i+3]-d)-p-1),i),
			p3=max((int)(upper_bound(p,p+n+2,p[i]+d)-p),i+3),
			p4=upper_bound(p,p+n+2,p[i+1]+d)-p-1;
		// int sl=0,sr=0;
		// debug("%d %d %d %d\n",p1,p2,p3,p4);
		ans+=1LL*max(p2-p1+1,0)*max(p4-p3+1,0);
	}
	// for(int i=1;i+3<=n;i++){
	// 	if(p[i]+d>=p[i+3]) continue;
	// 	if(nxt[nxt[i]]==i+3||pre[pre[i+3]]==i) continue;
	// 	if(p[i]+d>=p[i+2]&&p[i+1]+d>=p[i+3]) ans++;
	// }
	// for(int i=1;i<=n;i++)
	// 	debug("%d: %d %d\n",i,cl[i],cr[i]);
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T; cin>>C>>T;
	while(T--) solve();
	return 0;
}