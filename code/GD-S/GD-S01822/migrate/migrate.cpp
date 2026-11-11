#include<bits/stdc++.h>
#define x first
#define y second
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
typedef std::pair<int,int> pii;
using namespace std;
int a[2000005],c,len[2000005],dp[2000005],flg[100005];
void solve(){
	int n,d,ans=0;cin>>n>>d;
	rep(i,1,n) cin>>a[i];
	rep(s,1,n){
		rep(k,0,n) len[k]=0,dp[k]=0,flg[k]=0;
		dp[s]=1;
		int l=s,R=n;
		rep(k,s,n-1) if(a[k+1]-a[k]>d){R=k;break;}
		rep(k,s+1,R){
			while(a[k]-a[l]>d&&l+1<k) l++;
			len[k]=len[l]+1;
			rep(u,l,k) if(len[u]+1==len[k]){
				dp[k]+=dp[u];
				if(flg[u]){flg[k]=1;break;}
			}
//			cout<<dp[k]<<" ";
//			if(dp[k]>2) break;
			if(!flg[k]&&dp[k]==2) ans++;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	fre("migrate");
	int t;cin>>c>>t;
	while(t--) solve(); 
}

