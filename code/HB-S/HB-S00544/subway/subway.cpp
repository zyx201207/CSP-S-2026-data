#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const int M=500005;
const ll INF=0x3f3f3f3f;
ll c,n,m,d,q;
ll w[M];
ll k[N];
vector<pair<ll,ll>>A[M];
vector<ll>line[M];
ll ans=INF;

void dfs(ll cur,ll des,ll w,ll start,ll x,bool ok)
{   
    
    if(cur==des)
    {
        if(w+start<ans)
        {
            ans=w+start;
        }
        return;
    }
    if(w>ans) return;
    //if(line[cur].size()<=1) return;
    for(ll l:line[cur])
    {
        for(auto &e:A[l])
        {

            ll v=e.second;
            ll t=e.first;
            if(v==x&&ok==false)
            {
                start=t;
                ok=true;
            }
            if(v!=des) dfs(v,des,w+2*t,start,x);
            else dfs(v,des,w+t,start,x);
        }
    }
    return;
}
int main(){
    freopen("subway.in","r,",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            ll a,t;
            cin>>a>>t;
            A[i].push_back({t,a});
            line[a].push_back(i);

        }
    }
    for(int r=1;r<=q;r++)
    {
        ans=INF;
        ll x,y;
        cin>>x>>y;
        dfs(x,y,0,0,x,false);
        cout<<ans<<'\n';
    }
    
    return 0;
}