#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int k,id;
}c[10000100];
int n,m,a[10000100],d,z=1,maxn;
int l,r;
int cmp(node x,node y)
{
    return x.k<y.k;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
    {
        if(a[i-1]>=0&&a[i]>=0) c[i-1].k=abs(a[i]-a[i-1]);
        else c[i-1].k=abs(a[i]+a[i-1]);
        c[i-1].id=i-1;
    }
    sort(c+1,c+n,cmp);
    for(int i=1;i<=n&&i<=2e5;i++)
    {
        d=a[c[i].id];
        z=1;
        int m1=m;
        l=c[i].id-1;
        while(m1>0&&m1-d+a[l]>=0&&l>0)
        {
            int x=a[l];
            m1=m1-d+x;
            z++;
            l--;
        }
        maxn=max(maxn,z);
    }
    cout<<maxn;
    return 0;
}
