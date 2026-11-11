#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
const ll N=2e6+10;

ll x[N];

struct Node{
    ll num,ci,tiao;
};

list<Node> li;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ll c,t;cin>>c>>t;
    for(ll t1=1;t1<=t;t1++)
    {
        ll n,d;cin>>n>>d;
        for(ll i=1;i<=n;i++) cin>>x[i];
        ll ans=0;
        for(ll i=1;i<=n;i++)
        {
            li.clear();
            for(ll j=i+1;j<=n;j++)
            {
                if(x[j]-x[i]<=d)
                {
                    Node y;
                    y.ci=1;y.num=x[j];
                    y.tiao=1;li.push_back(y);
                    continue;
                }
                while(!li.empty()&&x[j]-li.front().num>d) li.pop_front();
                ll ci1=li.front().ci;
                ll cun=0;
                for(Node y:li)
                {
                    if(y.ci>ci1) break;
                    cun+=y.tiao;
                }
                Node y;
                y.ci=ci1+1;y.tiao=cun;
                if(cun==2) ans++;
                y.num=x[j];
                li.push_back(y);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
