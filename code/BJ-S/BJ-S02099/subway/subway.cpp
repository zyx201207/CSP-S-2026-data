#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,k,x,y;
ll w[500005];
ll a[505];
ll o[505][5005];
ll tg[505][5005];
struct sub
{
    ll d,t;
}p[505][5005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)
    {
        cin>>w[i];

    }
    for(ll i=1;i<=n;i++)
    {

        cin>>a[i];

        for(ll j=1;j<=a[i];j++)
        {
            cin>>p[i][j].d>>p[i][j].t;
            o[i][p[i][j].d]=1;
            tg[i][p[i][j].d]=j;

        }

    }
    ll cnt=0;
    for(ll i=1;i<=q;i++)
    {
        cin>>x>>y;
        cnt=0;
        cnt+=w[x];
        cnt+=w[y];
        ll hc=0;
        ll minn=1e9;
        for(ll k=1;k<=a[1];k++)
        {
            if(p[1][k].d==x)
            {
                cnt+=p[1][k].t;
                hc++;
            }
            else if(p[1][k].d==y)
            {
                cnt+=p[1][k].t;
                hc++;
            }

            if(o[2][p[1][k].d]==1)
            {
                minn = min(minn,(p[1][k].t+p[2][tg[2][p[1][k].d]].t));

            }


        }
        if(hc==2)
        {
            cout<<cnt<<"\n";

        }
        else
        {
            for(ll k=1;k<=a[2];k++)
            {
                if(p[2][k].d==x)
                {
                    cnt+=p[2][k].t;
                    hc++;
                }
                else if(p[2][k].d==y)
                {
                    cnt+=p[2][k].t;
                    hc++;
                }
            //if(p[2][k].d!=0) minn = min(minn,p[1][k].t);

            }

            cout<<cnt+minn<<"\n";
        }




    }
    return 0;
}

