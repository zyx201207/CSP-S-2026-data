#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],cnt,ans;
deque<int> q;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    q.push_back(a[1]);
    ans = 1;
    for(int i = 2;i<=n;i++)
    {
        cnt+=(a[i]-q.back())*q.size();
        while(!q.empty()&&cnt>m)
        {
            cnt-=a[i]-q.front();
            q.pop_front();
        }
        q.push_back(a[i]);
        ans = max(ans,(long long)q.size());
    }
    printf("%lld",ans);
    return 0;
}
