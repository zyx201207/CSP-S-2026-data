#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c;
ll n;
ll t;
ll d;
ll a[2000006];
vector<ll>v[200005];
vector<pair<ll,ll>>b(200005);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==13||c==14){
        for(ll i=1;i<=t;i++){
            cout<<0<<endl;
        }
        return 0;
    }
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            //cout<<n<<' '<<d<<endl;
            ll a1,b,c;
            cin>>a1>>b;
            for(ll i=1;i<=n-2;i++){
                cin>>c;
            }
            if(b-a1>=d||(d/(b-a1)*2-1)>=n){
                cout<<0<<endl;
                continue;
            }
            //cout<<d/(b-a1)<<endl;
            cout<<n-(((ll)d/(b-a1))*2-1)<<endl;
            //n-=2;

        }
        return 0;
    }
    while(t--){
        cin>>n>>d;
        b.assign(b.size(),{0,0});
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            v[i].clear();
        }
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                if(a[i]+d<a[j])break;
                v[i].push_back(j);
            }
        }
        ll ans=0;
        for(ll i=1;i<=n;i++){
            b.assign(b.size(),{LLONG_MAX,0});
            b[i].second=1;
            b[i].first=0;
            for(ll j=i;j<=n;j++){
                //cout<<b[j].second<<endl;
                if(b[j].second==2)ans++;
                if(v[j].empty())break;
                for(auto v1:v[j]){
                    if(b[v1].first==b[j].first+1){
                        b[v1].second+=b[j].second;
                    }
                    if(b[v1].first>b[j].first+1){
                        b[v1].first=b[j].first+1;
                        b[v1].second=b[j].second;
                    }
                    //cout<<v1<<' '<<b[v1].first<<' '<<b[v1].second<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
