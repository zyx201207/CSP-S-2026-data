#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
vector<ll> crd(200006);
map<pair<int, int>, vector<int>> roads;
void srch(int sti, int i, int j, int dp, int d){
    for(int l = 1;l <= j - i;l++){
        if(crd[i+l] - crd[i] <= d){
            if(i+l == j)roads[{sti,j}].push_back(dp+1);
            else srch(sti, i+l, j, dp+1,d);
        }
    }
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w",stdout);
    int c, t;
    cin >> c >> t;
    while(t--){
        crd.clear();
        roads.clear();
        ll n, d;
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> crd[i];
        }
        ll ans = 0;
        for(int i = 1;i <= n - 3;i++){
            for(int j = i+3;j <= n;j++){
                srch(i, i, j, 0, d);
            }
        }
        for(auto p : roads){
            //cout << "Type #" << t <<'\n';
            sort(p.second.begin(), p.second.end());
            //cout << p.first.first << ' ' << p.first.second << '\n';
            //for(int i = 0;i < p.second.size();i++) cout << p.second[i] << '\n';
            if(p.second[0] == p.second[1] && p.second[1] != p.second[2]) ans++;
        }
        cout << ans<<'\n';
    }
}
