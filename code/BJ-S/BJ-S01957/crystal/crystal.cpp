# include <bits/stdc++.h>
using namespace std;
# define int long long
const int N = 5e5+5;
int n, a[N], m, ans;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);

    int l = 1, tot = 0;
    for (int i=1;i<=n;i++){
        while (l < i){
            if (tot > m){
                tot -= (a[i] - a[l]);
                l++;
            }
            else{
                break;
            }
        }
        int have = i - l + 1;
        tot += (a[i+1] - a[i]) * have;
        ans = max(ans, have);
        //cout << i << " : " << l << " " << tot << " " << have << endl;
    }
    cout << ans << endl;
    return 0;
}
