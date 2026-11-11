#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ps putchar(' ')
#define pt putchar('\n')
const ll N=17;
const ll M=2e6+7;
void in(ll &num){
	ll k=1,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') k=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		f=f*10+ch-'0';
		ch=getchar();
	}
	num=k*f;
	return;
}
void ot(ll num){
	if(num<0) putchar('-'),num*=-1;
	if(num>9) ot(num/10);
	putchar(num%10+'0');
	return;
}
void out(ll num){
	ot(num),ps;
	return;
}
ll n,m,d;
ll x[N],sum[N],dp[N];
ll a[M];
ll c,T;
ll ans=0;
ll vis[N];
ll cnt[N][N],minn[N][N];
void dfs(ll now){
	if(now==n+1){
		vector<ll> ls;
		for(ll i=1;i<=n;i++) if(vis[i]==1) ls.push_back(i);
		if(ls.size()<2) return;
		for(ll i=1;i<ls.size();i++){
			if(x[ls[i]]-x[ls[i-1]]>d) return;
		}
		ll l=ls[0],r=ls[ls.size()-1];
		if(minn[l][r]>ls.size()-1){
			cnt[l][r]=1;
			minn[l][r]=ls.size()-1;
//			out(l),out(r),pt;
			return;
		}
		if(minn[l][r]==ls.size()-1){
			cnt[l][r]++;
			return;
		}
		return;
	}
	vis[now]=1;
	dfs(now+1);
	vis[now]=0;
	dfs(now+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	in(c),in(T);
//	out(n),pt;
	if(c==11||c==12){
		while(T--){
			in(n),in(d);
			for(ll i=1;i<=n;i++) in(a[i]);
			out(0),pt;
		}
		return 0;
	}
	if(c==13||c==14){
		while(T--){
			in(n),in(d);
			for(ll i=1;i<=n;i++) in(a[i]);
			out(0),pt;
		}
		return 0;
	}
	while(T--){
		in(n),in(d);
		memset(minn,0x3f3f3f,sizeof(minn));
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		for(ll i=1;i<=n;i++) in(x[i]);
		ans=0;
		dfs(1);
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(cnt[i][j]==2) ans++; 
			}
		}
		out(ans),pt;
	}
	return 0;
}
/*
cd C:\Users\Administrator\Desktop\GD-S01884\migrate
fc /w /n migrate.out migrate1.ans

				while(x[j]-x[ltp]>d&&ltp<j) ltp++;
				rtp=max(rtp,ltp);
				while(x[j+1]-x[rtp]>d&&rtp<=j) rtp++;
				out(j),out(ltp),out(rtp);
				if(ltp==j) break;
				dp[j]=max(0ll,sum[rtp-1]-sum[ltp-1]);
				sum[j]=sum[j-1]+dp[j];
				if(sum[rtp-1]-sum[ltp-1]==2) cnt++;
				out(dp[j]),out(sum[j]),out(cnt),pt;
*/
