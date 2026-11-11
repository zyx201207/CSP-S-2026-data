#include <iostream>
using namespace std;
#define int long long
#define limit -1000000000000

int dp[10005][10005],a[100005],maxans=limit;

int n,m;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) dp[i][1]=a[i];
    if(m==1) 
    {
		for(int i=0;i<n;i++) maxans=max(maxans,a[i]);
		cout<<maxans;
		return 0;
	}
    for(int i=1;i<n;i++)
    {
        for(int j=2;j<=i+1;j++)
        {
            int ma=limit;
            for(int k=0;k<i;k++)
            {
				//cout<<k<<"->"<<i<<dp[k][j-1]<<' '<<dp[i][j]<<endl;
                ma=max(ma,(dp[k][j-1] & a[i]));
            }
            dp[i][j]=ma;
            //cout<<i<<' '<<j<<' '<<ma<<endl;
            if(j==m) maxans=max(ma,maxans);
        }
    }
    cout<<maxans;
}
