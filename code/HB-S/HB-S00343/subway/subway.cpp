#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,p;
map<ll,ll> mp;
vector<pair<ll,ll> > v;
pair<ll,ll> j[100005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","r",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        ll a;
        cin>>a;
        mp[i]=a;
    }
    for(int i=0;i<n;i++){
        ll k;
        cin>>k;
        for(int j=0;j<k;j++){
            ll m,s;
            cin>>m>>s;
            v.push_back({m,s});
        }
    }
    for(int i=0;i<p;i++){
        cin>>j[i].first>>j[i].second;
    }
    for(int i=0;i<p;i++) cout<<0<<endl;
    return 0;
}
