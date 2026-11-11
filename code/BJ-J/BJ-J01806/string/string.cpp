#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N];
char c[N];
int cnt=0;
struct node{
    int num;
    char s;
}d[N];
int ans=0;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld %c",&a[i],&c[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(c[i]==d[cnt].s)
        {
            d[cnt].num+=a[i];
        }
        else
        {
            d[++cnt].s=c[i];
            d[cnt].num=a[i];
        }
    }
    n=cnt;
    int l=1,r=n;
    while(l<=r)
    {
        if(d[l].s==d[r].s)
        {
            int minn=min(d[l].num,d[r].num);
            if(d[l].num>minn)
            {
                d[l].num-=minn;
                r--;
                continue;
            }
            else if(d[r].num>minn)
            {
                d[r].num-=minn;
                l++;
                continue;
            }
            else if(d[l].num==d[r].num)
            {
                l++;
                r--;
                continue;
            }
        }
        else
        {
            int minn=min(d[l].num,d[r].num);
            ans+=minn;
            if(d[l].num>minn)
            {
                d[l].num-=minn;
                r--;
                continue;
            }
            else if(d[r].num>minn)
            {
                d[r].num-=minn;
                l++;
                continue;
            }
            else if(d[l].num==d[r].num)
            {
                l++;
                r--;
                continue;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
