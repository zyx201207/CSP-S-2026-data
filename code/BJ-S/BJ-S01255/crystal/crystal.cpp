#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long ans=0;
long long sum=0;
queue<int> q;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        sum+=(q.size()*(a[i]-a[i-1]));
        while(!q.empty()&&sum>m)
        {
            sum-=(a[i]-a[q.front()]);
            q.pop();
        }
        q.push(i);
        ans=max(ans,1ll*(i-q.front()+1));
    }
    printf("%lld\n",ans);
    return 0;
}