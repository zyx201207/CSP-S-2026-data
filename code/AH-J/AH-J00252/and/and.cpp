#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,maxn,ans,sum;
struct f
{
    int v[32];
    int t;
    int len;
    int check;
}a[200010];
int cnt[32];
bool cmp(f x,f y)
{
    return x.len>y.len;
}
bool cmp2(f x,f y)
{
    int pos1=0,pos2=0;
    for(int i=x.check;i>=1;i--)
    {
        if(x.v[i]&&cnt[i]>=m)pos1=i;break;
    }
    for(int i=y.check;i>=1;i--)
    {
        if(y.v[i]&&cnt[i]>=m)pos2=i;break;
    }
    return pos1>pos2;
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].t;
        int num=a[i].t;
        maxn=max(num,maxn);
        if(i>1)sum=num&sum;
        else sum=a[i].t;
        int cnt1=0;
        while(num)
        {
            a[i].v[++cnt1]=num%2;
            a[i].len++;
            if(num%2)cnt[cnt1]++;
            num/=2;
        }
    }
    if(m==1){cout<<maxn;return 0;}
    if(m==n){cout<<sum;return 0;}
    if(m==2)
    {
        int maxn=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                maxn=max(maxn,a[i].t&a[j].t);
            }
        }
        cout<<maxn;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    int minn=a[m].len;
    for(int i=1;i<=n;i++)
    {
        a[i].check=minn;
    }
    sort(a+1,a+n+1,cmp2);
    ans=a[1].t;
    for(int i=2;i<=m;i++)
    {
        ans=ans&a[i].t;
    }
    cout<<ans;
    return 0;
}
