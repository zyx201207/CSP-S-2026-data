#include <bits/stdc++.h>
using namespace std;

long long c,t,n,d,ans[100001];
vector<long long> a;

bool have(long long ep,long long fp,long long sp)
{
    short match=0;
    for(long long v:a)
    {
        if(v==ep||v==fp||v==sp)
        {
            match++;
        }
    }
    return match==3 ? true:false;
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int f=0;f<t;f++)
    {
        a.clear();
        ans[f]=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            long long x;
            cin>>x;
            a.push_back(x);
        }
        long long anslen=2*d-1;
        for(int i=0;a[i]+anslen<=a[n-1];i++)
        {
            if(have(a[i]+anslen,a[i]+d,a[i]+d-1))
            {
                ans[f]++;
            }
        }
    }
    for(int f=0;f<t;f++)
    {
        cout<<ans[f]<<"\n";
    }
    int fclose(0);
    return 0;
}
