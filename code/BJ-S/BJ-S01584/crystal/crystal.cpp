#include <bits/stdc++.h>
using namespace std;
long long a[500010],a1[500010];
long long cnt,maxx,ans;
long long f;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >>n>>m;
    long long aver=0;
    for(int i=1;i<=n;i++)
    {
        cin >>a1[i];
    }
    sort(a1+1,a1+n+1);
    int tmp=n/2+(n%2);
    cnt=a1[tmp];
    for(int i=1;i<=n;i++)
    {
        a1[i]=a1[i]-cnt;
        if(a1[i]<0)
        {
            f+=a1[i];
        }
    }
    while(m>0&&tmp<=n)
    {
     
        if(f==0)
        {
            tmp++;
            for(int i=1;i<=n;i++)
            {
                a1[i]+=cnt;
            }
            int cnt=a1[tmp];
            for(int i=1;i<=n;i++)
            {
                a1[i]=a1[i]-cnt;
            }
        }
        for(int i=tmp;i>=1;i--)
        {
            if(a1[i]<0&&m>0)
            {
                if(m+a1[i]>=0)
                {
                    m+=a1[i];
                    a1[i]=0;
                }
                else
                {
                    //a1[i]+=m;
                    m=0;
                }
            }
        }
        if(m<=0)
        {
            break;
        }
        maxx=-1e9;
        for(int i=1;i<=n;i++)
        {
            a1[i]+=cnt;
            a[a1[i]]++;
            maxx=max(a1[i],maxx);
        }
        ans=-1e9;
        for(int i=1;i<=maxx;i++)
        {
            ans=max(ans,a[i]);
            a[i]=0;
        }
        if(ans==n)
        {
            cout <<ans;
            return 0;
        }
        tmp++;
        cnt=a1[tmp];
        for(int i=1;i<=n;i++)
        {
            a1[i]=a1[i]-cnt;
        }
    }
    maxx=-1e9;
    for(int i=1;i<=n;i++)
    {
        a1[i]+=cnt;
        a[a1[i]]++;
        maxx=max(a1[i],maxx);
    }
    for(int i=1;i<=maxx;i++)
    {
        ans=max(ans,a[i]);
    }
    cout <<ans;
    return 0;
}
