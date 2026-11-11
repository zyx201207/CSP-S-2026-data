#include<iostream>
#include<cstring>
#define int long long
#define F(i,x,y) for(int i=x;i<=y;i++)
#define F2(i,x,y) for(int i=x;i>=y;i--)
#define f(x,y) for(auto x:y)
#define lt(x) x&-x
#define d2(l,r) (l+r>>1)
#define ls(i) i<<1
#define rs(i) i<<1|1
using namespace std;
const int N=3e2+15;
int n,d,x[N],dp[N][N],vis[N][N];
void solve(){
	cin>>n>>d;
	F(i,1,n) cin>>x[i];
	memset(dp,63,sizeof dp);
	memset(vis,0,sizeof vis);
	int ans=0;
	F(i,1,n){
		F(j,i+1,n){
			if(x[j]-x[i]<=d){
				dp[i][j]=1;
				vis[i][j]=1;
				continue;
			}
			int cnt=0;
			F(k,i,j){
				int dis=x[j]-x[k];
				if(dis>d) continue;
				if(dp[i][j]>dp[i][k]+1){
					cnt=vis[i][k];
					dp[i][j]=dp[i][k]+1;
				}else if(dp[i][j]==dp[i][k]+1) cnt+=vis[i][k];
//				if(i==1&&j==6) cout<<dp[i][k]<<' '<<i<<' '<<k<<endl;
			}
			if(cnt==2){
				ans++;
//				cout<<i<<' '<<j<<endl;
			}
			vis[i][j]=cnt;
		}
	}
	cout<<ans<<endl;
}
int rubbish,T;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>rubbish>>T;
	while(T--) solve();
	return 0;
}
