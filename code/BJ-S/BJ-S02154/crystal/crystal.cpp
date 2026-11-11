#include<bits/stdc++.h>
using namespace std;
long long a[500005];
queue<long long> q;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    a[0]=a[1];
    long long d=0,ans=1;
    for(int i=1;i<=n;i++)
    {
        long long x=a[i]-a[i-1],y=q.size();
        d+=x*y;
        if(d<=m)
        {
            q.push(a[i]);
            long long z=q.size();
            ans=max(ans,z);
        }
        else
        {
            while(d>m&&q.size())
            {
                d=d-(a[i]-q.front());
                q.pop();
            }
            q.push(a[i]);
            long long z=q.size();
            ans=max(ans,z);
        }
    }
    cout<<ans;
    return 0;
}