#include <iostream>
#include <algorithm>
using namespace std;
long long a[500003];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    sort(a+1, a+n+1);
    long long M = m, ans = 1, cnt = 0;
    for(long long l = 1, r = 2; r <= n; ){
        if(M-(r-l)*(a[r]-a[r-1]) >= 0){
            M -= ((r-l)*(a[r]-a[r-1]));
            ans = max(ans, r-l+1);
            r++;
        }
        else{
            M += (a[r-1]-a[l]);
            l++;
            ans = max(ans, r-l+1);
        }
    }
    cout << ans << endl;
    return 0;
}
