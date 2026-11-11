#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int sum[N];
int nextt[N];
int cnt=0;
int ans=1;
bool cmp(int x,int y)
{
    return x<y;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    int pre=1;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
        if(i>2 && a[i]-a[i-1]==a[i-1]-a[i-2])cnt++;
        if(a[i]!=a[i-1] && i!=1)
        {
            nextt[pre]=i-1;
            pre=i-1;
        }
    }
    if(cnt==n-2)//dengchashulie
    {
        int cur=0;
        int d=a[n]-a[n-1];//gongcha
        if(d==0)
        {
            printf("%lld\n",n);
            exit(0);
        }
        for(int i=1;i<=n;i+=d)
        {
            cur+=i*d;
            if(cur>m)
            {
                ans=i;
                break;
            }
        }
        if(cur<=m)ans=n;
        printf("%lld\n",ans);
        exit(0);
    }
    nextt[pre]=n;
    nextt[n]=n+1;
    for(int i=1;i<=n;i=nextt[i])
    {
        for(int j=1;j<i;j++)
        {
            if((i-j)*a[i]-(sum[i-1]-sum[j-1])<=m)
            {
                ans=max(ans,i-j+1);
                break;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
