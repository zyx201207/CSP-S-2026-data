#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2000005;
const int INF =0x3f3f3f3f;
ll x[N];ll res=1;
void dfs(ll cur,ll des,ll mind,ll t,ll d)
{
    if(cur==des)
    {
        if(t<mind)
        {
            mind=t;
            res=1;
        }
        else if(t==mind) res++;
    }
    for(int i=cur+1;i<=des;i++)
    {
        if(x[i]-x[cur]>d) break;
        dfs(i,des,mind,t+1,d);
    }
}
bool check(ll a,ll b,ll d)
{
    res=0;
    for(int i=a+1;i<=b;i++)
    {
        if(x[i]-x[i-1]>d) return false;
    }
    dfs(a,b,INF,0,d);
    //cerr<<res<<'\n';
    if(res==2) return true;
    else return false;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll c,t;
    cin>>c>>t;
    if(c<=10)
    {
        while(t--)
        {
            ll n,d;
            cin>>n>>d;
            memset(x,0,sizeof(x));
            for(int i=1;i<=n;i++)
            {
                cin>>x[i];
            }
            ll ans=0;
            for(int i=1;i+3<=n;i++)
            {
                for(int j=i+3;j<=n;j++)
                {
                    if(check(i,j,d)) ans++;
                }
            }
            cout<<ans<<'\n';
        }
    }
    
    return 0;
}