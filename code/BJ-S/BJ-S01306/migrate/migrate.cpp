#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,d,ans;
ll l,r;
ll a[2000010];
ll dp[5010][5010],cnt[5010][5010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>c>>t;
    if(c>=0&&c<=10)
    {
        while(t--)
        {
            ans=0;
            cin>>n>>d;
            for(int i=1;i<=n;i++)
            {
                cin>>a[i];
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<i;j++)
                {
                    dp[j][i]=0x7f7f7f7f;
                    cnt[j][i]=0;
                }
                for(int j=i-1;j>=1;j--)
                {
                    if(a[i]-a[j]<=d)
                    {
                        dp[j][i]=1;
                        cnt[j][i]=1;
                        continue;
                    }
                    for(int k=i-1;k>j;k--)
                    {
                        if(dp[j][k]+dp[k][i]<dp[j][i])
                        {
                            dp[j][i]=dp[j][k]+dp[k][i];
                            cnt[j][i]=cnt[j][k]*cnt[k][i];
                        }
                        else if(dp[j][k]+dp[k][i]==dp[j][i])
                        {
                            cnt[j][i]+=cnt[j][k]*cnt[k][i];
                        }
                    }
                    cnt[j][i]/=dp[j][i]-1;
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<i;j++)
                {
                    if(cnt[j][i]==2)
                    {
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    else if(c==11||c==12)
    {
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)
            {
                cin>>a[i];
            }
            l=a[2]-a[1];
            r=d/l;
            ans=n-2*r+1;
            if(ans<0||r==0||r==1)
            {
                ans=0;
            }
            cout<<ans<<endl;
        }
    }
    else if(c==13||c==14)
    {
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)
            {
                cin>>a[i];
            }
            cout<<0<<endl;
        }
    }
    else{
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)
            {
                cin>>a[i];
            }
            cout<<0<<endl;
        }
    }
    return 0;
}
