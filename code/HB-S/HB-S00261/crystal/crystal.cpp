#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[505050],l[505050],t=1919810,p,s;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
    {
        if(ch=='-')f=0;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return f?x:-x;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--)
    {
        p=p-(a[i+1]-a[i])*max(0ll,i+1-t);
        t=min(t,i);
        while(t)
        {
            if(p+a[i]-a[t-1]<=m)
            {
                p+=a[i]-a[t-1];
                t--;
            }
            else
            {
                l[i]=t;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)s=max(s,i-l[i]+1);
    cout<<s;
}
