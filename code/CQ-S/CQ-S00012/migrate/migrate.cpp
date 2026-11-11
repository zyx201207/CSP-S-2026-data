#include <bits/stdc++.h>
#define double long double
#define int long long
using namespace std;
const double eps=1e-6;
const int inf=0x3f3f3f3f3f3f3f3f,N=2e6+10;
int a[N],p[N],ans1[N],ans2[N];
int n,d;
void solve()
{
    memset(p,0,sizeof p);
    memset(ans1,0,sizeof ans1);
    memset(ans2,0,sizeof ans2);
    cin>>n>>d;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int id=1;
    for (int i=1;i<=n;i++)
    {
        while (id<n&&a[id+1]-a[i]<=d)
        {
            id++;
        }
        p[i]=id;
    }
    // cerr<<p[8]<<' '<<p[9]<<' '<<p[10]<<'\n';
    for (int i=n;i>=1;i--)
    {
        // ans2[i]=p[i]-i;
        if (p[i]==i)
        {
            ans2[i]=0;
            continue;
        }
        ans2[i]+=p[p[i]]-p[p[i]-1];
        // cerr<<p[p[i]]<<' '<<p[p[i]-1]<<'\n';
        if (p[p[i]]!=p[p[i]-1])
        {
            ans2[i]+=ans2[p[i]];
        }
        // cerr<<i<<':'<<ans2[i]<<'\n';
    }
    int sum=0;
    // cerr<<'\n';
    for (int i=n;i>=1;i--)
    {
        if (p[i]==i)
        {
            continue;
        }
        if (p[i]>i+1)
        {
            ans1[i]=p[p[i]-1]-p[p[i]-2];
        }
        if (p[p[i]-1]!=p[p[i]])
        {
            ans1[i]+=ans1[p[i]]-(p[p[i]]>p[i]+1&&p[i]>i+1?max(0ll,min(p[p[p[i]]-1],p[p[p[i]-1]])-p[p[p[i]]-2]):0);
        }
        else if (p[i]==i+1||p[p[i]-2]!=p[p[i]])
        {
            ans1[i]+=ans2[p[i]];
        }
        sum+=ans1[i];
        // cerr<<i<<':'<<ans1[i]<<'\n';
    }
    cout<<sum<<'\n';
    return;
}
signed main()
{
    // freopen("migrate/migrate5.in","r",stdin);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case,TestCase=1;
    cin>>Case>>TestCase;
    for (int CaseId=1;CaseId<=TestCase;CaseId++)
    {
        solve();
    }
    return 0;
}

/*
g++ migrate.cpp -o migratee -std=c++14 -O2
./migratee

0 1
5 3
-3 0 2 3 4
*/