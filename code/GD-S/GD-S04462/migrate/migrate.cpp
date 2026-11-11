#include <bits/stdc++.h>
#define int long long 
using namespace std;

int _C,_T;

int n,d,x[2000010];

void scan()
{
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&x[i]);
    }
}

void solveA()
{
    if(n==1)
    {
        printf("0\n");
        return;
    }
    int a=x[2]-x[1];
    int m=d/a;
    if(m<=1)
    {
        printf("0\n");
        return;
    }
    printf("%lld\n",max(n-2*m+1,0ll));
}

int dis[5010],cnt[5010],sum[5010];
deque<int>q;

void calc(int s)
{
    while(!q.empty())q.pop_back();
    for(int i=0;i<=n;i++)
    {
        cnt[i]=0;
        sum[i]=0;
        dis[i]=1e18;
    }
    cnt[s]=1;
    sum[0]=1;
    dis[s]=0;
    q.push_back(s);
    // printf("%lld\n",s);
    for(int i=s+1,j=s;i<=n;i++)
    {
        // for(int j=i-1;j>=s;j--)
        // {
        //     if(x[i]-x[j]>d)
        //     {
        //         break;
        //     }
        //     if(dis[j]+1<dis[i])
        //     {
        //         dis[i]=dis[j]+1;
        //         cnt[i]=cnt[j];
        //     }
        //     else if(dis[j]+1==dis[i])
        //     {
        //         cnt[i]=min(10ll,cnt[i]+cnt[j]);
        //     }
        // }
        while(x[j]+d<x[i])
        {
            sum[dis[j]]-=cnt[j];
            j++;
        }
        while(!q.empty()&&x[q.front()]+d<x[i])q.pop_front();
        if(!q.empty())
        {
            // printf("%lld: %lld %lld\n",i,q.front(),q.back());
            dis[i]=dis[q.front()]+1;
            cnt[i]=sum[dis[q.front()]];
        }
        else break;
        sum[dis[i]]+=cnt[i];
        while(!q.empty()&&dis[q.back()]>=dis[i])q.pop_back();
        q.push_back(i);
    }
}

void solve1()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        calc(i);
        for(int j=i+1;j<=n;j++)
        {
            ans+=(cnt[j]==2);
        }
    }
    printf("%lld\n",ans);
}

void solveB()
{
    int m=1;
    for(;m<=n;m++)
    {
        if(x[1]+d>=x[m]&&x[m]+d>=x[n])
        {
            break;
        }
    }
    if(m==1)
    {
        printf("0\n");
        return;
    }
    int k=m;
    while(k<=n&&x[m-1]+d>=x[k])
    {
        k++;
    }
    k--;
    int l=m-1;
    while(l>0&&x[l]+d>=x[m+1])
    {
        l--;
    }
    l++;
    int r=m-1;
    while(r>0&&x[r]+d>=x[m+2])
    {
        r--;
    }
    r++;
    // printf("l=%lld r=%lld k=%lld\n",l,r,k);
    printf("%lld\n",(r-l)*(n-k));
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    scanf("%lld%lld",&_C,&_T);
    while(_T--)
    {
        scan();
        if(_C<=10)
        {
            solve1();
        }
        else if(_C==11||_C==12)
        {
            solveA();
        }
        else
        {
            solveB();
        }
    }

    return 0;
}