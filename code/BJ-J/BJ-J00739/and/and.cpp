#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],d[200005],maxc,b[200005];
long long an(long long a,long long b)
{
    long long c[35]={0},d[35]={0},k=1,t[35]={0};
    while(a)
    {
        c[k++]=a%2;
        a/=2;
    }
    k=1;
    while(b)
    {
        d[k++]=b%2;
        b/=2;
    }
    k=0;
    for(int i=1;i<=34;i++)
        t[i]=(c[i] and d[i]);
    for(int i=34;i>0;i--)
        k=k*2+t[i];
    return k;
}
void dg(long long x,long long s)
{
    if(x>m)
    {
        long long c=pow(2,20)-1;
        for(int i=1;i<=m;i++)
            c=an(c,d[i]);
        if(c>maxc)
            maxc=c;
        return ;
    }
    for(int i=s+1;i<=n;i++)
        if(b[i]==0)
        {
            b[i]=1;
            d[x]=a[i];
            dg(x+1,i);
            b[i]=0;
        }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=2000)
    {
        dg(1,0);
        cout<<maxc;
        return 0;
    }
    if(n-1==m)
    {
        cout<<"0";
        return 0;
    }
    long long c=pow(2,30)-1;
    sort(a,a+n+1);
    for(int i=n;i>=n-m+1;i--)
        c=an(c,a[i]);
    cout<<c;
    return 0;
}