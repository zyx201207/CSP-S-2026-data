#include<bits/stdc++.h>
using namespace std;
const long long MAXN=10000000;
long long cnt[MAXN+MAXN];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans=0,mx=LLONG_MIN,mn=LLONG_MAX;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        long long t;
        cin>>t;
        cnt[t+MAXN]++;
        mx=max(mx,t);
        mn=min(mn,t);
    }
    long long l=mn,r=mx;
    for(long long i=l;i<=r;i++)
    {
        //cout<<i<<endl;;
        long long tm=m;
        long long t=cnt[i+MAXN];
        //cout<<t<<"a\n";
        for(long long j=1;;j++)
        {
            if(cnt[i+j+MAXN]!=0)
            {
                long long tx=min(cnt[i+j+MAXN],tm/j);
                tm-=tx*j;
                t+=tx;
            }
            //cout<<t<<"a\n";
            if(cnt[i-j+MAXN]!=0)
            {
                long long tx=min(cnt[i-j+MAXN],tm/j);
                tm-=tx*j;
                t+=tx;
            }
            //cout<<t<<"a\n";
            if(tm<j)
            {
                break;
            }
        }
        ans=max(ans,t);
    }
    cout<<ans;
    return 0;
}
