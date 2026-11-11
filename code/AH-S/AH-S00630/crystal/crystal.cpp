#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int a[500005];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;n=read();m=read();bool t=true;
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=3)
        {
            t=false;
        }
    }
    if(t==true)
    {
        int d=a[2]-a[1];
        for(int i=1;i<=n;i++)
        {
            if(i*(i+1)/2*d>m)
            {
                cout<<i;
                return 0;
            }
        }
    }
    sort(a+1,a+1+n);
    int maxx=-1;
    for(int i=1;i<=n;i++)
    {
        int ans=m;int sum=1;
        for(int j=i-1;j>=1;j--)
        {
            if(ans-(a[i]-a[j])>=0)
            {
                ans-=(a[i]-a[j]);sum++;
            }
            else
            {
                break;
            }
        }
        maxx=max(maxx,sum);
    }
    cout<<maxx;
    return 0;
}
