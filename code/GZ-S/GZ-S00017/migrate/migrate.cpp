//GZ-S00017，刘书成，贵阳市南明区华麟学校
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	freopen("migrate.out","w",stdout);
	freopen("migrate.in","r",stdin);
    ios::sync_with_stdio(false);cin.tie(0);

    ll c,t;
    cin>> c >> t;
    for(ll j = 0;j<t;j++){
        ll n,d,g =0;
        cin >>n>>d;
        vector<ll> a(n);
        for(ll i = 0;i<n;i++){
            cin >> a[i];
        }
        for(ll k = 0;k<n-1;k++){
            for(ll i= k+1;i<n;i++){
                vector<ll> q;
                q.emplace_back(a[k]);
                while(find(q.begin(),q.end(),a[i])==q.end()){
                    ll sz = q.size();
                    for(ll ii = 0;ii<sz;ii++){
                        for(ll iii = 1;iii<=d;iii++){
                            q.emplace_back(q[ii]+iii);
                        }
                    }
                    q.erase(q.begin(),q.begin()+sz);
                }
                if(count(q.begin(),q.end(),a[i])==2){
                    g++;
                }
            }
        }
        cout << g << '\n';
    }

    return 0;
}
