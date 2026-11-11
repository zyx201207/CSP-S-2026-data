#include <bits/stdc++.h>
#define int long long
using namespace std;

int read()
{
    char c=getchar();
    int x=0,f=1;
    while (!isdigit(c))
    {
        if (c=='-') f=-f;
        c=getchar();
    }
    while (isdigit(c))
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
int a[2000010],r[2000010];
int dp[2000010][2][2];

void solve()
{
    int n=read(),d=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1,j=1;i<=n;i++)
    {
        while (j<=n && a[j]-a[i]<=d) j++;
        r[i]=j-1;
        //cout<<r[i]<<' ';
    }
    //cout<<"\n";
    r[0]=0;
    for (int i=n;i>=2;i--)
    {
        for (int j=0;j<2;j++)
        {
            for (int k=0;k<2;k++)
            {
                int ll=r[i-2],mm=r[i-1],rr=r[i];
                //i+1~ll
                dp[i][j][k]=0;
                //ll+1~mm
                if (max(ll+1,i+1)<=mm && j+k==0) dp[i][j][k]+=mm-max(ll,i);
                //mm+1~rr
                if (max(mm+1,i+1)<=rr && k==1) dp[i][j][k]+=rr-max(mm,i);
                if (rr!=i)
                {
					int rp=k+1+(r[i-1]==r[i]?j+1:0)+(r[i-2]==r[i]?1:0);
					int lp=k+1+(r[i-1]>=r[i]-1?j+1:0)+(r[i-2]>=r[i]-1?1:0);
					if (rp<3 && (lp<3 || r[r[i]-1]<=r[i])) dp[i][j][k]+=dp[r[i]][(lp<3?lp-1:0)][rp-1];
				}	
				//cout<<i<<' '<<j+1<<' '<<k+1<<":"<<dp[i][j][k]<<"\n";
            }
        }
    }
    int ans=0;
    //cout<<"ans:\n";
    for (int i=1;i<=n;i++)
    {
		ans+=dp[r[i]][0][0];
		//cout<<r[i]<<" 0 0:"<<dp[r[i]][0][0]<<"\n";
	}
    cout<<ans<<"\n";
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c=read(),t=read();
    while (t--) solve();
}
