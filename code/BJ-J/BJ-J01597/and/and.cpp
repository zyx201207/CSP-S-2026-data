#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, a[200005], lt = 0;
string s[200005];

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1, a+1+n, greater<ll>());
    for(int i=1; i<=n; i++){
        ll t = a[i];
        while(t){
            char c = (char)((t%2)+'0');
            s[i] += c;
            t /= 2;
        }
        lt = max(lt, (ll)(s[i].size()));
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=lt-s[i].size(); j++){
            s[i] += '0';
        }
        reverse(s[i].begin(), s[i].end());
    }

    vector<ll> v;
    for(int i=0; i<lt; i++){
        v.clear();
        bool flag = 0;
        for(int j=1; j<=n; j++){
            if(s[j][i] == '1'){
                v.push_back(j);
                if(v.size()>=m){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag) break;
    }

    if(v.size() == 0) cout<<0;
    else{
        ll ans = a[v[0]];
        for(int i=1; i<v.size(); i++){
            ans &= a[v[i]];
        }
        cout<<ans;
    }
    return 0;
}
