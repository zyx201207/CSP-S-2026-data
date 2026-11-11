#include <bits/stdc++.h>
#define start_code signed main(){
#define stop_code return 0;}
#define elif else if
#define Tests int T;for(cin>>T;T --;)
#define infile(x) freopen(#x".in","r",stdin)
#define outfile(x) freopen(#x".out","w",stdout)
#define ansfile(x) freopen(#x".ans","w",stdout)
#define openfile(x) (infile(x),outfile(x))
#define fastio() (ios::sync_with_stdio(0),cin.tie(0),cout.tie(0))
#define mem(a,v) memset(a,v,sizeof(a))
#define int long long
using namespace std;
namespace solution1
{
	const int N = 5005;
	int n,d,x[N],dp[N][N],sum[N][N],ans,pos[N];
	void main()
	{
		Tests
		{
			cin>>n>>d,ans = 0,mem(pos,0);
			for (int i = 1;i <= n;i ++) cin>>x[i];
			for (int i = 2,ptr = 1;i <= n;i ++)
			{
				while (x[i]-x[ptr] > d) ptr ++;
				pos[i] = ptr;
			}
			for (int cur = 1;cur < n;cur ++)
			{
				mem(dp,0),mem(sum,0),dp[cur][0] = 1;
				for (int i = cur;i <= n;i ++) sum[i][0] = sum[i-1][0]+dp[i][0];
				for (int j = 1;j <= n-cur;j ++)
				{
					for (int i = cur+1;i <= n;i ++) dp[i][j] = sum[i-1][j-1]-sum[pos[i]-1][j-1];
					for (int i = cur;i <= n;i ++) sum[i][j] = sum[i-1][j]+dp[i][j];
				}
				for (int i = cur+1;i <= n;i ++)
				{
					for (int j = 1;j <= n-cur;j ++)
						if (dp[i][j])
						{
							if (dp[i][j] == 2) ans ++;
							goto Label;
						}
					Label:;
				}
			}
			cout<<ans<<'\n';
		}
	}
}
int CID;
start_code
openfile(migrate);
fastio();
cin>>CID;
solution1::main(); 
stop_code
