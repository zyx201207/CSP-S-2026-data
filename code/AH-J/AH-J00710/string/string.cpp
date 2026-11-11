#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
long long sum,cnt,ans,t,tt,cntt,sumt;
char c[200005];
signed main(void)
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    sumt=sum;
    if(sum%2==1)
    {
        sum+=1;
    }
    for(int i=1;i<=n;i++)
    {
        cnt+=a[i];
        if(cnt>=sum/2)
        {
            tt=i;
            break;
        }
    }
    t=n;
    for(int i=1;i<tt;)
    {
        if(t==tt)
        {
            break;
        }
        if(a[i]==a[t])
        {
            if(c[i]!=c[t])
            {
                ans+=a[i];

            }
            a[t]=0;
            a[i]=0;
            i++;
            t--;
        }
        else
        {
            if(a[i]<a[t])
            {
                if(c[i]!=c[t])
                {
                    ans+=a[i];
                }
                a[t]-=a[i];
                a[i]=0;
                i++;
                continue;
            }
            if(a[i]>a[t])
            {
                if(c[i]!=c[t])
                {
                    ans+=a[t];
                }
                a[i]-=a[t];
                a[t]=0;
                t--;
                continue;
            }
        }
    }
    int yb=cnt-sum/2;
    int zb=a[tt]-yb;
    if(sumt%2==1)
    {
        zb--;
    }
    if(yb>zb)
    {
        for(int i=1;i<tt;i++)
        {
            if(a[i]!=0 && c[i]!=c[tt])
                ans+=a[i];
        }
    }
    if(yb<zb)
    {
        for(int i=tt+1;i<=n;i++)
        {
            if(a[i]!=0 && c[i]!=c[tt])
                ans+=a[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
