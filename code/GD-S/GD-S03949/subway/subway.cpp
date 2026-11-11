#include <bits/stdc++.h>
using namespace std;

int w[1000005];
int k[1000005],a[1000005],t[1000005];//,dp[1000005][1000005];
int c, n, m,d,q,tmp,cnt,station=1;
int main()
{
    ios::sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0);
    cin >> c, n, m, d, q;
    struct none{
        int x[100005];
        int y[100005];
    };
    none plan;
    struct none2{
        int go_through[100005][100005];
        int go_time[100005][100005];
    };
    none2 fast_found_index;

    for(int i=1;i<=m;i++)
    {
        cin>> tmp;
        w[i]=tmp;
        tmp=0;
        
    }
    for(int i=1;i<=m;i++)
    {
        cin>>k[i];
        for(int j=1;j<=1+2* k[i];j++)
        {
            cin>> a[j] >> t[j];
            fast_found_index.go_through[i][j] = a[j];
            fast_found_index.go_time[i][j] = t[j];
        }
    }
    for(int u=1;u<=q;u++)
    {
        cin >> plan.x[u] >> plan.y[u];
    }
    tmp=0;
    for(int r=1;r<=q;r++)
    {
        if(fast_found_index.go_through[plan.x[r]][plan.y[r]] == plan.y[r])
        {
            cnt=w[plan.x[r]] + fast_found_index.go_time[plan.x[r]][plan.y[r]];
        }
        else
        {
            while(fast_found_index.go_through[station][plan.y[r]] != plan.y[r])
            {
                for(int i=1;i<=m;i++)
                {
                    if(fast_found_index.go_time[station][plan.y[r]]+w[i] <= tmp)
                    {
                        tmp=fast_found_index.go_time[station][plan.y[r]]+w[i];
                    }
                    station=fast_found_index.go_through[station][plan.y[r]]+w[i];
                }
            }

                
        }
        cout <<  cnt+tmp << endl;
    }
    return 0;
}
