#include<bits/stdc++.h>
using namespace std;
bool bit(long long shu,long long wei)
{
    long long zh=shu>>wei;
    if(zh%2ll==1)
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n=0,m=0,ans=0;
    cin>>n>>m;
    vector<long long> a(n+2,0);
    vector<bool> flag(n+2,true);
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(long long i=29;i>=0;i--)
    {
        long long cnt=0;
        for(long long x=1;x<=n;x++)
        {
            if(flag[x]==false)
            {
                continue;
            }
            if(bit(a[x],i)==true)
            {
                cnt++;
            }
        }
        if(cnt>=m)
        {
            ans=ans+(1<<i);
            for(long long x=1;x<=n;x++)
            {
                if(flag[x]==false)
                {
                    continue;
                }
                if(bit(a[x],i)==false)
                {
                    flag[x]=false;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
