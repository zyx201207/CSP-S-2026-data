#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n;
ll m,a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int j=1,ans=0;
    ll tot=0;
    for(int i=1;i<=n;i++)
    {
        tot+=(i-j)*(a[i]-a[i-1]);
        while(j<i&&tot>m)
        {
            tot-=a[i]-a[j];
            j++;
        }
        ans=max(ans,i-j+1);
    }
    printf("%d",ans);
    return 0;
}