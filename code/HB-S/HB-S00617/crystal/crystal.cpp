#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],cnt[500001],sum,t,maxn,cha;
bool flag=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==2) cha=a[i]-a[i-1];
        if(a[i]-a[i-1]!=cha&&i!=1) flag=0;
    }
    if(flag)
    {
        for(int i=1;i<=500000;i+=cha)
        {
            if(m>=i)
            {
                maxn++;
                m-=i;
            }
            else
            {
                cout<<maxn+1;
                return 0;
            }
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        t=m;
        for(int j=i;j>1;j--)
        {
            sum+=a[j]-a[j-1];
            if(t>=sum)
            {
                cnt[i]++;
                t-=sum;
            }
        }
        sum=0;
    }
    for(int i=1;i<=n;i++) maxn=max(maxn,cnt[i]);
    cout<<maxn+1;
    return 0;
}
