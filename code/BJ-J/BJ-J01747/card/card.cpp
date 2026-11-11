#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
ll n,m;
ll a[500005];
ll tong[300005];
vector<ll> vt;
ll o,i,j,k;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(o=1; o<=n; o++)
    {
        for(i=o; i<=n; i++)
        {
            if(i==o)
            {
                vt.push_back(a[i]);
            }
            else
            {
                for(j=0; j<vt.size(); j++)
                {
                    if(vt[j]==a[i])
                    {
                        ll ttt=vt.size();
                        for(k=1; k<=(ttt-j); k++)
                        {
                            vt.pop_back();
                        }
                        break;
                    }
                }
                vt.push_back(a[i]);
            }
        }
        for(j=0; j<vt.size(); j++)
        {
            tong[vt[j]]++;
        }
        vt.clear();
    }
    for(i=1; i<=m; i++)
    {
        cout<<tong[i]<<' ';
    }
    return 0;
}
/*
  RP++
  AC++
  AK++
*/
