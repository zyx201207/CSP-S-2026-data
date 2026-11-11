#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct str{
    ll a;
    ll i;
};
vector<vector<str>> l(0,vector<str>(0));
vector<ll> v(0,0);
vector<ll> z(0,0);
vector<vector<str>> t(0,vector<str>(0));
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll wbbb,n,m,d,q;
    cin>>wbbb>>n>>m>>d>>q;
    l.resize(n+1,vector<str>(0)); //tong
    t.resize(m+1,vector<str>(0)); //yousha
    z.resize(m+2000);                //jinzhan
    for(ll i=1;i<=m;i++) cin>>z[i];
    for(ll i=0;i<n;i++){
        ll k;
        cin>>k;
        l[i].resize(k);
        for(ll j=0;j<k;j++){
            cin>>l[i][j].i>>l[i][j].a;
            t[l[i][j].i].push_back({l[i][j].a,i});
        }
    }
    for(ll i=0;i<q;i++){
        v.resize(m+1000,1000000000000000009ll);      //jilu
        ll st,ed;
        cin>>st>>ed;
        queue<str> qu;
        qu.push({0,st});
        while(!qu.empty()){
            auto tt=qu.front();
            qu.pop();
            if(tt.a>v[tt.i]){
                continue;
            }
            v[tt.i]=tt.a;
            for(int i=0;i<t[tt.i].size();i++){
                for(int j=0;j<l[t[tt.i][i].i].size();j++){
                    qu.push({tt.a+l[t[tt.i][i].i][j].a+t[tt.i][i].a,l[t[tt.i][i].i][j].i});
                }
            }
        }
        if(v[ed]==1000000000000000009ll) cout<<-1<<"\n";
        cout<<v[ed]+z[st]+z[ed]<<"\n";
    }
    return 0;
}
