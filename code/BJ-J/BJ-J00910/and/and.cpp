#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    if(m == 1){
        long long maxn = -1;
        long long now;
        for(int i = 0; i < n; i++){
            cin >> now;
            maxn = max(maxn,now);
        }
        cout << maxn;
        return 0;
    }
    if(m == n){
        long long ans;
        cin >> ans;
        for(int i = 1; i < n; i++){
            long long now;
            cin >> now;
            ans = ans & now;
        }
        cout << ans;
        return 0;
    }
    return 0;
}
