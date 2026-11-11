#include <bits/stdc++.h>
using namespace std;
#define pa pair<int,int>
#define fi first
#define sc second
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define REP(i,x,y) for(int i=(x);i>=(y);i--)
#define fastIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
const int N=2000003;
int testId,T;
int n,pre[N],nxt[N];
pa dis[N];
ll m,a[N],s[N];
namespace BRUTE{
	void Main(){
		cin>>n>>m;
		rep(i,1,n) cin>>a[i];
		int z=n;
		REP(i,n,1){
			while(z>1&&a[i]-a[z-1]<=m) --z;
			pre[i]=z;
		}
		ll ans=0;
		rep(i,1,n){
			rep(j,1,n) s[j]=0,dis[j]={0,0};
			dis[i]={0,1}; s[i]=1;
			int r=i,tmp;
			rep(j,i+1,n){
				if(pre[j]==j) break;
				tmp=max(i,pre[j]); r=max(r,tmp);
				dis[j].fi=dis[tmp].fi+1;
				while(r<j-1&&dis[r+1].fi==dis[j].fi-1) ++r;
				dis[j].sc=min(3ll,s[r]-s[tmp-1]);
				if(dis[j].sc==2) ++ans;
				s[j]=s[j-1]+dis[j].sc;
			}
		}
		cout<<ans<<"\n";
	}
}
namespace SpecA{
	void Main(){
		cin>>n>>m;
		rep(i,1,n) cin>>a[i];
		ll k=m/(a[2]-a[1]);
		if(k<2){
			cout<<"0\n";
			return;
		}
		cout<<max(0ll,1ll*n-2*k+1)<<"\n";
	}
}
namespace fff{
	
int prs[N],nxs[N],f[N],g[N];
	void Main(){
		cin>>n>>m;
		rep(i,1,n){
			cin>>a[i];
			prs[i]=nxs[i]=0;
		}
		int z=1;
		rep(i,1,n){
			while(z<n&&a[z+1]-a[i]<=m) ++z;
			nxt[i]=z; prs[z]++;
		}
		z=n;
		REP(i,n,1){
			while(z>1&&a[i]-a[z-1]<=m) --z;
			pre[i]=z; nxs[z]++;
		}
		ll ans=0;
		rep(i,1,n){
			f[i]=prs[i]-(nxt[i]==i)+1;
			if(pre[i]!=i&&nxt[pre[i]]==i){
				f[i]+=f[pre[i]]-1;
			}
		}
		REP(i,n,1){
			g[i]=nxs[i]-(pre[i]==i)+1;
			if(nxt[i]!=i&&pre[nxt[i]]==i){
				g[i]+=g[nxt[i]]-1;
			}
		}
		rep(i,1,n-1){
			int pr=prs[i+1]-(nxt[i+1]==i+1)-(nxt[i]==i+1);
			int nx=nxs[i]-(pre[i]==i)-(pre[i+1]==i);
			int l=pre[i+1],r=nxt[i];
			if(l<i&&i+1<r&&nxt[l]==i+1&&pre[r]==i){
				pr+=f[l]-1;
				nx+=g[r]-1;
			}
			ans+=1ll*pr*nx;
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	fastIO;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>testId>>T;
	if(testId<=10){
		while(T--) BRUTE::Main();
	}
	else if(testId<=12){
		while(T--) SpecA::Main();
	}
	else{
		while(T--) fff::Main();
	}
	return 0;
}
