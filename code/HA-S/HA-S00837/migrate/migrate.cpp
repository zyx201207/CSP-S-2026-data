#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define ft first
#define sd second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rem(i,a,b) for(int i=(a);i>=(b);i--)
#define PII pair<int,int>
using namespace std;

int SUB;
const int N=2e6+10,INF=0x3f3f3f3f;
LL n,d,a[N];

struct S6{
	LL ans;
	LL dis[5005],vis[5005],in[5005],dp[5005];
	vector<int> dv[5005];
	void solve_sub(int s){
		queue<PII> q;
		rep(i,s,n) dis[i]=INF,vis[i]=0,dv[i].clear(),in[i]=0,dp[i]=0;
		dis[s]=0,vis[s]=1,q.push({s,0});
		while(q.size()){
			int hi=q.front().ft,hw=q.front().sd;q.pop();
			dis[hi]=hw;
			rep(i,hi+1,n){
				if(a[i]-a[hi]>d) break;
				if(!vis[i]) vis[i]=1,q.push({i,hw+1});
			}
		}
		rep(i,s,n) rep(j,i+1,n){
			if(a[j]-a[i]>d) break;
			if(dis[i]+1==dis[j]) dv[i].pb(j),in[j]++;
		}
		queue<int> tq;
		tq.push(s),dp[s]=1;
		while(tq.size()){
			int hi=tq.front(); tq.pop();
			for(int ni:dv[hi]){
				if(in[ni]==-1) continue;
				dp[ni]+=dp[hi];
				if(dp[ni]>2) in[ni]=-1;
				else if(--in[ni]==0) tq.push(ni);
			}
		}
		//rep(i,s,n) cout<<dis[i]<<' ';cout<<'\n';
		//rep(i,s,n) cout<<dp[i]<<' ';cout<<'\n';
		rep(i,s,n) if(dp[i]==2) ans++;
	}
	void solve(){
		ans=0;
		rep(i,1,n) solve_sub(i);
		cout<<ans<<'\n';
	}
}s6;

struct S12{
	void solve(){
		LL det=a[2]-a[1],mx=d/det;
		if(mx<=1) return cout<<0<<'\n',void();
		if(mx*2>n) return cout<<0<<'\n',void();
		cout<<n-mx*2+1<<'\n';
	}
}s12;

struct S14{
	void solve(){
		LL mid=0;
		rep(i,1,n) if(a[i]-a[1]<=d&&a[n]-a[i]<=n){mid=i;break;}
		LL ans=0;
		rep(i,1,mid-1){
			LL tmid=upper_bound(a+1,a+1+n,a[i]+d)-a-2;
			if(tmid==i) continue;
			LL r=upper_bound(a+1,a+1+n,a[tmid]+d)-a-1;
			LL l=upper_bound(a+1,a+1+n,a[tmid-1]+d)-a-1;
			ans+=r-l;
		}
		cout<<ans<<'\n';
	}
}s14;

void solve(){
	cin>>n>>d;
	rep(i,1,n) cin>>a[i];
	if(n==1) return cout<<0<<'\n',void();
	if(a[n]-a[1]<=d) return cout<<0<<'\n',void();
	if(SUB<=10) return s6.solve();
	if(11<=SUB&&SUB<=12) return s12.solve();
	if(13<=SUB&&SUB<=14) return s14.solve();
}

int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	//freopen("migrate4.in","r",stdin);//freopen("std.out","w",stdout);//fc /W std.out 
	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int SUB,T;cin>>SUB>>T;
	while(T--) solve();
	return 0;
}
