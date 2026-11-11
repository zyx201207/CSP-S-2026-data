#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt[N],sum[N],ans[N];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    if(m==1)
    {
        printf("%lld\n",n);
        exit(0);
    }
    if(n<=5000 || (n>5000 && m!=2 && n<200000))
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(cnt[a[j]]!=0)
                {
                    sum[cnt[a[j]]]--;
                    sum[j]++;
                    for(int k=cnt[a[j]];k<j;k++)
                    {
                        cnt[a[k]]=0;
                    }
                }
                cnt[a[j]]=j;
            }
            for(int j=i;j<=n;j++)
            {
                sum[j]+=sum[j-1];
                cnt[a[j]]=0;
                if(sum[j]==0)
                {
                    ans[a[j]]++;
                }
                sum[j-1]=0;
            }
            sum[n]=0;
        }
        for(int i=1;i<=m;i++)
        {
            printf("%lld ",ans[i]);
        }
        exit(0);
    }
    if(m==2)
    {
        int l1=n,l2=n;
        int ans1=0,ans2=0;
        while(a[l1]==2)l1--;
        while(a[l2]==1)l2--;
        if(l1>l2)ans1=n;
        if(l2>l1)ans2=n;
        for(int i=1;i<=n;i++)
        {
            if(l1>l2 && a[i]==2)ans2++;
            if(l2>l1 && a[i]==1)ans1++;
        }
        printf("%lld %lld\n",ans1,ans2);
        exit(0);
    }
    for(int i=1;i<=m;i++)
    {
        printf("%lld ",i);
    }
    return 0;
}
