#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N=2e6+10,inf=1e18;
int a[N],l[N],r[N],val[N],L[N],R[N];
long long n,m;
int up(int x)
{
    return lower_bound(a+1,a+n+1,x)-a;
}
int down(int x)
{
    return upper_bound(a+1,a+n+1,x)-a-1;
}
void run()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        l[i]=r[i]=L[i]=R[i]=val[i]=0;
        long long x;
        cin>>x;
        a[i]=x;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        int j=down(a[i]+m);
        if(j!=i&&i==up(a[j]-m))
        {
            l[j]=i,r[i]=j;
        }
    }
    for(int i=1;i<n;i++)
    {
        int j=down(a[i]+m);
        if(up(a[j]-m)!=i)
        {
            L[j]++;
        }
    }
    for(int i=2;i<=n;i++)
    {
        int j=up(a[i]-m);
        if(down(a[j]+m)!=i)
        {
            R[j]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(l[i])l[i]=l[l[i]]+1+L[i];
        else l[i]=1+L[i];
    }
    for(int i=n;i>=1;i--)
    {
        if(r[i])r[i]=r[r[i]]+1+R[i];
        else r[i]=1+R[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int k=down(a[i]+m);
        int p=k-1;
        if(i<p)
        {
            val[p]+=(up(a[p]-m)==i?l[i]:1);
        }
    }
    for(int i=1;i<=n;i++)
    {
        int p=up(a[i]-m),k=p+1;
        if(k<i)
        {
            ans+=val[p]*(down(a[k]+m)==i?r[i]:1);
        }
    }
    cout<<(long long)ans<<endl;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    long long c,t;
    cin>>c>>t;
    while(t--)run();
    return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

6
*/