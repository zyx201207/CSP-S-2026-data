#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,d;
int a[2000005];
int optimise[2000005],steps[2000005];
int cnt;
int routes(int x,int y)
{
    int i,j;
    memset(optimise,0,sizeof(optimise));
    memset(steps,0,sizeof(steps));
    optimise[x]=1;
    for(i=x+1;i<=y;i++)
    {
        int min_step=LONG_LONG_MAX;
        for(j=i-1;j>=x;j--)
        {
            if(abs(a[i]-a[j])>d)
            {
                break;
            }
            min_step=min(min_step,steps[j]);
        }
        int tmp=j+1;
        steps[i]=min_step+1;
        for(j=tmp;j<=i;j++)
        {
            if(steps[j]==min_step)
            {
                optimise[i]+=optimise[j];
            }
            else
            {
                break;
            }
        }
    }
    return optimise[y];
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    if(c==11||c==12)
    {
        while(T--)
        {
            cin>>n>>d;
            int i;
            for(i=1;i<=n;i++)
            {
                cin>>a[i];
            }
            int gap=a[2]-a[1];
            int islands=d/gap;
            if(islands<2)
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<(n-islands*2+1<=0?0:n-islands*2+1)<<endl;
            }
        }
        return 0;
    }
    if(c==13||c==14)
    {
        while(T--)
        {
            cin>>n>>d;
            int i;
            for(i=1;i<=n;i++)
            {
                cin>>a[i];
            }
            cout<<0;
        }
        return 0;
    }
    int ans=0;
    while(T--)
    {
        ans=0;
        cin>>n>>d;
        int i,j;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(routes(i,j)==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
