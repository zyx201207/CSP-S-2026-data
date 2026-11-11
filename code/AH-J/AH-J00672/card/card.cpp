#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],b[300005],c[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++)
    {
        vector<ll> q;
        memset(b,0,sizeof(b));
        for(ll j=i;j<=n;j++)
        {
            q.push_back(a[j]);
            b[a[j]]++;
            if(b[a[j]]>1)
            {
                q.pop_back();
                b[a[j]]--;
                while(!q.empty())
                {
                    if(q.back()==a[j]) break;
                    b[q.back()]--;
                    q.pop_back();
                }
            }
        }
        while(!q.empty())
        {
            c[q.back()]++;
            q.pop_back();
        }
    }
    for(ll i=1;i<=m;i++)
        cout<<c[i]<<" ";
    return 0;
}
/*

*/
