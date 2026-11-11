#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define F(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define dF(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
#define pb push_back
#define fi first
#define se second
#define mkp make_pair
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define bll __int128
#define inf 1000000000
using namespace std;
void fre(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
}
bool ST;
template<typename T>inline void chkmax(T&x,const T&y){ x=max(x,y); }
template<typename T>inline void chkmin(T&x,const T&y){ x=min(x,y); }
const int maxn=2000005;
ll k,a[maxn];
int n,to[maxn],testid;
int dp[maxn],dp1[maxn];
void subA(){
	ll ans=0;
	F(u,1,n){
		vector<int>vec;
		int cnt=0,lst=u;
		for(int x=u;x<=n;x=to[x]){
			if(++cnt>4)break;
			if(x-2>lst)vec.push_back(x-2);
			if(x-1>lst)vec.push_back(x-1);
			vec.push_back(x),lst=x;
			if(x==to[x]||x==n)break;
		}
		dp[0]=0,dp1[0]=1;
		F(i,1,SZ(vec)-1)dp[i]=inf,dp1[i]=0;
		F(i,0,SZ(vec)-1){
			int u=vec[i],lim=to[u];
			F(j,i+1,SZ(vec)-1){
				if(vec[j]>lim)break;
				if(dp[j]>dp[i]+1)dp[j]=dp[i]+1,dp1[j]=dp1[i];
				else if(dp[j]==dp[i]+1)dp1[j]=min(dp1[j]+dp1[i],3);
			}
			if(dp1[i]==2)++ans;
			if(i==SZ(vec)-1)continue;
			int L=vec[i]+1,R=min(to[vec[i]],vec[i+1]-1);
			if(L>R)continue;
			if(dp1[i]==2){
				if(i&&dp[i]==dp[i-1])chkmax(L,to[vec[i-1]]+1);
				if(L<=R)ans+=R-L+1;
			} else{
				if(i==0||dp1[i-1]!=1||dp[i]!=dp[i-1])continue;
				chkmin(R,to[vec[i-1]]);
				if(i>1&&dp[i]==dp[i-2])chkmax(L,to[vec[i-2]]+1);
				if(L<=R)ans+=R-L+1;
			}
		}
	}
	cout<<ans<<'\n';
}
void solve(int cid){
	cin>>n>>k;
	F(i,1,n)cin>>a[i];
	to[0]=0;
	F(i,1,n){
		to[i]=max(to[i-1],i);
		while(to[i]<n&&a[to[i]+1]-a[i]<=k)++to[i];
	}
	if(n>20&&(testid==11||testid==12))return subA(),void();
	ll ans=0;
	F(u,1,n){
		vector<int>vec;
		int lst=u;
		for(int x=u;x<=n;x=to[x]){
			if(x-2>lst)vec.push_back(x-2);
			if(x-1>lst)vec.push_back(x-1);
			vec.push_back(x),lst=x;
			if(x==to[x]||x==n)break;
		}
		dp[0]=0,dp1[0]=1;
		F(i,1,SZ(vec)-1)dp[i]=inf,dp1[i]=0;
		F(i,0,SZ(vec)-1){
			int u=vec[i],lim=to[u];
			F(j,i+1,SZ(vec)-1){
				if(vec[j]>lim)break;
				if(dp[j]>dp[i]+1)dp[j]=dp[i]+1,dp1[j]=dp1[i];
				else if(dp[j]==dp[i]+1)dp1[j]=min(dp1[j]+dp1[i],3);
			}
			if(dp1[i]==2)++ans;
			if(i==SZ(vec)-1)continue;
			int L=vec[i]+1,R=min(to[vec[i]],vec[i+1]-1);
			if(L>R)continue;
			if(dp1[i]==2){
				if(i&&dp[i]==dp[i-1])chkmax(L,to[vec[i-1]]+1);
				if(L<=R)ans+=R-L+1;
			} else{
				if(i==0||dp1[i-1]!=1||dp[i]!=dp[i-1])continue;
				chkmin(R,to[vec[i-1]]);
				if(i>1&&dp[i]==dp[i-2])chkmax(L,to[vec[i-2]]+1);
				if(L<=R)ans+=R-L+1;
			}
		}
	}
	cout<<ans<<'\n';
}
bool ED;
signed main(){
	fre(),ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int allT;cin>>testid>>allT;
	F(_,1,allT)solve(_);
	cerr<<"time used: "<<((double)clock()/CLOCKS_PER_SEC)<<endl;
	cerr<<"memory used: "<<(abs(&ST-&ED)/1024.0/1024.0)<<"MiB"<<endl;
}
// g++ c.cpp -o a -std=c++14 -O2