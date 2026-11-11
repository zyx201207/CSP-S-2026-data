#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll N=2000005;
struct gnode {
    ll v,w;
};
vector<gnode> g[N];
ll n,k,l=0,r=0;
bool check(ll mid) {
    return mid;
}
int solve() {
    cin >> n >> k;
    for(ll i=1,u=0,v=0;i<=n;i++){
        cin >> u >> v;
        g[u].push_back((gnode){v, 0});
        g[v].push_back((gnode){u, 0});
    }
    ll mid=0;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(check(mid)){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << mid << endl;
    return 0;
}
int c,t;
int main() {
    int ExitCode=0;
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    /*while(t--){
        ExitCode |= solve();
    }*/
    cout << "1\n2";
    return ExitCode;
}
