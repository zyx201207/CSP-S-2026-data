#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll INF=1e9+10;
vector<ll> w,di;
vector<vector<ll>> pass,t;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    w.resize(m+1,0);
    di.resize(n+1,0);
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    pass.resize(n+1,vector<ll>(m+1,0));
    t.resize(n+1,vector<ll>(m+1,0));
    for(int i=1;i<=n;i++){
        cin>>di[i];
        for(int j=1;j<=di[i];j++){
            cin>>pass[i][j]>>t[i][j];
        }
    }
    while(q--){
        int s,t;
        cin>>s>>t;
        bool flags=false,flagt=false;
        ll ms=INF;
        ll mt=INF;
        for(int i=1;i<=n;i++){
            ll ts=INF;
            ll tt=INF;
            for(int j=1;j<=m;j++){
                if(pass[i][j]==s) {
                    flags=true;
                    ts=min(ts,w[j]);
                }
                if(pass[i][j]==s) {
                    flagt=true;
                    tt=min(tt,w[t]);
                }
                if(flags&&flagt) break;
            }
            ms=min(ms,ts);
            mt=min(mt,tt);
        }
        if(flags&&flagt){
            cout<<ms+mt<<'\n';
            continue;
        }
    }
    return 0;
}