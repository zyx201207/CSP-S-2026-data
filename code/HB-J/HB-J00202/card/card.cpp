#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n,m;
ll a[500010],u[300010],stk[500010],sttop = 0;
bool v[300010];
ll ans[300010];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(ll i = 1;i <= n;i++)
        scanf("%lld",&a[i]);
    for(ll i = 0;i < n;i++)
    {
        for(ll j = i + 1;j <= n;j++)
        {
            if(v[a[j]] && u[a[j]] <= sttop)
            {
                for(ll k = sttop;k > u[a[j]];k--)
                    v[stk[k]] = 0;
                sttop = u[a[j]];
            }
            else
            {
                v[a[j]] = true;
                stk[++sttop] = a[j];
                u[a[j]] = sttop;
            }
            //printf("%lld %lld\n",sttop,a[j]);
        }
        /*printf("fin: %lld ",sttop);
        for(ll j = 1;j <= m;j++)
        {
            if(v[j] && u[j] <= sttop)
                printf("Y ");
            else
                printf("N ");
        }
        printf("\n");*/
        for(ll j = 1;j <= m;j++)
            if(v[j] && u[j] <= sttop)
                ans[j]++;
        memset(v,0,sizeof(v));
        sttop = 0;
    }
    for(ll i = 1;i <= m;i++)
        printf("%lld ",ans[i]);
    return 0;
}