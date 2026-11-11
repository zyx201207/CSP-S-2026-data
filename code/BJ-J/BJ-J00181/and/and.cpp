#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5;
int n, m, ans = (1<<30) - 1, p = 0;
pii a[maxn];
bool cmp(pii x, pii y){
    if(x.first != y.first) return x.first > y.first;
    if(x.second != y.second) return x.second > y.second;
    return false;
}
int low(int x){
    int nu = 0;
    while(x) x = x & (x-1), nu++;
    return nu;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>a[i].second, a[i].first = low(a[i].second);
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= m; i++){
        p = 0;
        while((ans & a[i + p].second) == 0 && i + p <= n){
            p += 1;
            if(i + p == n && ans & a[i + p].second == 0){
                cout<<"0\n";
                return 0;
            }
        }
        ans = ans & a[i + p].second; 
    }
    cout<<ans<<"\n";
    return 0;
}