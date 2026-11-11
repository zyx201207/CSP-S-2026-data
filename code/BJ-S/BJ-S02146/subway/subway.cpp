#include <bits/stdc++.h>
using namespace std;
#define ll long long
int GUNMU;
ll n,m,d,q,x,y;
struct line
{
    ll t_c;
    ll line_name;
};
struct pst
{
    ll k=0;
    ll dz;
    ll d_t;
    line lin[21];
}a[500010];
ll line_size,line_station_name;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>GUNMU;
    cin>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        a[i].dz=i;
        cin>>a[i].d_t;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>line_size;
        for(int j=1;j<=line_size;j++)
        {
            cin>>line_station_name;
            a[line_station_name].k++;
            cin>>a[line_station_name].lin[a[line_station_name].k].t_c;
            a[line_station_name].lin[a[line_station_name].k].line_name=i;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        ll ans=0;
        ans+=a[x].d_t;
        ans+=a[y].d_t;

        cout<<ans<<endl;
    }

    return 0;
}
