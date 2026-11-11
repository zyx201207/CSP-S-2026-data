#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3e5+10;
ll n,m,a[N],g[N],num[N];
deque<ll> dq;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++)
    {
        dq.clear();
        memset(g,0,sizeof g);
        for(ll j=i;j<=n;j++)
        {
            g[a[j]]++;
            if(g[a[j]]==2)
            {
                while(dq.back()!=a[j])
                {
                    g[dq.back()]--;
                    dq.pop_back();
                }
                dq.pop_back();
                g[a[j]]=1;
            }
            dq.push_back(a[j]);
        }
        for(ll i=1;i<=m;i++)if(g[i]!=0)num[i]++;
    }
    for(ll i=1;i<=m;i++)cout<<num[i]<<" ";
    return 0;
}
