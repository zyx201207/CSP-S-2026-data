#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define gc getchar_unlocked
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
ll read(){
	ll x(0);char c(gc()),f(0);
	while(c<'0'||c>'9')f^=c=='-',c=gc();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=gc();
	return f?-x:x;
}
ll x[2000010];
int cnt[2000010];
struct nd{int d,cnt;ll expt;};
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	fre("migrate");int c=read(),T=read();
	while(T--){
		ll n(read()),d(read());
		for(int i=1;i<=n;++i)x[i]=read();
		ll ans=0;
		if(n>5000){
			for(int i=1;i<n;++i){
				queue<nd>q;
				q.push({1,1,x[i]+d}),cnt[1]=1;
				int cnt1=0;
				for(int j=i+1;j<=n;++j){
					cnt[j-i+1]=0;
					while(q.size()&&q.front().expt<x[j])cnt[q.front().d]-=q.front().cnt,q.pop();
					if(!q.size())break;
					const int nwc=min(cnt[q.front().d],3),nwd=q.front().d;
					ans+=nwc==2,q.push({nwd+1,nwc,x[j]+d}),cnt[nwd+1]+=nwc;
					cnt1+=nwc==1||nwc==3;
					if(nwc==2)cnt1=0;
					if(i<n-500&&cnt1>10){ll t=x[j]+d-n/2600,j1=j;j=upper_bound(x+1,x+n+1,t)-x-2;j=max(1ll*j,j1+n/50);cnt1=0;continue;}
				}
			}
		}else for(int i=1;i<n;++i){
			queue<nd>q;
			q.push({1,1,x[i]+d}),cnt[1]=1;
			for(int j=i+1;j<=n;++j){
				cnt[j-i+1]=0;
				while(q.size()&&q.front().expt<x[j])cnt[q.front().d]-=q.front().cnt,q.pop();
				if(!q.size())break;
				const int nwc=min(cnt[q.front().d],3),nwd=q.front().d;
				ans+=nwc==2,q.push({nwd+1,nwc,x[j]+d}),cnt[nwd+1]+=nwc;
			}
		}
		cout<<ans<<'\n';
		// cerr<<ans<<'\n';
	}
	return 0;
}//17:27