#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=305;
const int M=2e6+5;
struct node
{
    int v;
    ll cnt;
};
node dp[N][N];
ll x[M];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    int n;
    ll d;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<=n;i++)
        {
            dp[i][i].v=0;
            dp[i][i].cnt=1;
        }
        int ans=0;
        for(int len=2;len<=n;len++)
        {
            for(int l=1,r=l+len-1;r<=n;l++,r++)
            {
                int mn=1e9;
                ll cnt=0;
                for(int k=r-1;k>=l;k--)
                {
                    if(x[r]-x[k]<=d)
                    {
                        if(mn>dp[l][k].v+1)
                        {
                            mn=dp[l][k].v+1;
                            cnt=dp[l][k].cnt;
                        }
                        else if(mn==dp[l][k].v+1)
                        {
                            cnt+=dp[l][k].cnt;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                if(cnt==2)
                {
                    ans++;
                }
                dp[l][r].v=mn;
                dp[l][r].cnt=cnt;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}