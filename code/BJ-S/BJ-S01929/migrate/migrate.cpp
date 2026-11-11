#include <bits/stdc++.h>
#define int long long
#define N 2000005

using namespace std;

int c,t,n,d,x[N],dis,le[N],ri[N];
void solvea()
{
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        dis=x[2]-x[1];
        if(d<2*dis||d>x[n]-x[1]){cout<<0<<'\n';continue;}
        cout<<n-(2*d/dis)+1<<'\n';
    }
}
void solveb()
{
    while(t--)
    {
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        int l=1,r=1;
        while(r<=n)
        {
            while(x[r]-x[l]>d)++l;
            le[r]=l,++r;
        }
        l=n,r=n;
        while(l)
        {
            while(x[r]-x[l]>d)--r;
            ri[l]=r,--l;
        }
        for(int i=1;i<=n;++i)
            for(int j=i+2;j<=n;++j)
            {
                if(ri[i]-le[j]==1)
                    ans++;
            }
        cout<<ans<<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12)
        solvea();
    else if(1<=c&&c<=10)
        solveb();
    else
    {
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)
                cin>>x[i];
            for(int i=1;i<=n;i++)
                cout<<0<<'\n';
        }
    }
    return 0;
}
