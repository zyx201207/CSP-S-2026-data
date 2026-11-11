#include<bits/stdc++.h>

using namespace std;
long long read()
{
char ch;
long long w=1,s=0;
ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') w=-1;
    ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
    s=s*10+ch-'0';
    ch=getchar();
    }
return w*s;
}
int n;
long long a[500005];
unsigned long long m,sum[500005];
bool check(int x)
{
unsigned long long ans=sum[x],minn=sum[x];
    for(int i=x+1;i<=n;i++)
    {
    ans=ans+(x-1)*(unsigned long long)(a[i]-a[i-1])-(a[i-1]-a[i-x]);
    minn=min(minn,ans);
    }
    if(minn<=m) return true;
    else return false;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++)
    {
    a[i]=read();
    }
    sort(a+1,a+n+1);
    sum[1]=0;
    for(int i=2;i<=n;i++)
    {
    sum[i]=sum[i-1]+(i-1)*(unsigned long long)(a[i]-a[i-1]);
    }
    int l=1,r=n,mid;
    while(l<r)
    {
    mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}
