#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
array<ull,200003>a;
array<bool,200003>v;
int n,m;
ull ans;
void csp_orz_rpplusplus(int d,ull an)
{
    if(d==m)
    {
        ans=max(ans,an);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!v[i])
        {
            v[i]=1;
            csp_orz_rpplusplus(d+1,an&a[i]);
            v[i]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    if(m==1)
    {
        ull maxa=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            maxa=max(maxa,a[i]);
        }
        cout<<maxa;
    }
    else if(m==n)
    {
        cin>>ans;
        for(int i=1;i<n;i++)
        {
            cin>>a[i];
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==2)
    {
        ull maxa=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                maxa=max(maxa,(a[i]&a[j]));
            }
        }
        cout<<maxa;
    }
    else if(m==n-1)
    {
        ull maxa=0;
        array<ull,200003>aa;
        ull x,y;
        cin>>x>>y;
        aa[0]=y;
        for(int i=1;i<n;i++)
        {
            aa[i]=x;
        }
        for(int i=2;i<n;i++)
        {
            aa[i]&=y;
        }
        for(int i=2;i<n;i++)
        {
            cin>>a[i];
            maxa=max(maxa,a[i]);
            for(int j=0;j<i;j++)
            {
                aa[j]&=a[i];
            }
            for(int j=i+1;j<n;j++)
            {
                aa[j]&=a[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            maxa=max(maxa,aa[i]);
        }
        cout<<maxa;
    }
    else if(n<=31)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            v[i]=1;
            csp_orz_rpplusplus(1,a[i]);
            v[i]=0;
        }
        cout<<ans;
    }
    else
    {
        int k=(log(n)/log(2));
        cout<<(1<<(k+1-m))-1<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
    }
    return 0;
}
