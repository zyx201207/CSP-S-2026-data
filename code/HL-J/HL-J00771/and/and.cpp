#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],vis[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(register int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    ll sum = a[n];
    for(register int i=1;i<m;i++)
    {
        ll b = n,mx=-1,ip=0;
        while(b--)
        {
            if(mx < (sum & a[b])&&vis[b]==0){
                    ip = b;
                    mx = (sum & a[b]);
            }
        }
        sum = mx;
        vis[ip] = 1;
    }
    printf("%lld",sum);
    return 0;
}
