# include <bits/stdc++.h>
using namespace std;
# define int long long
const int N = 3e5+5;
int a[N], ans;
char c[N];

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
    }

    int l = 1, r = n;
    while (l < r){
        if (a[l] > a[r]){
            if (c[l] != c[r]){
                ans += a[r];
            }
            a[l] -= a[r];
            r--;
        }
        else if (a[l] < a[r]){
            if (c[l] != c[r]){
                ans += a[l];
            }
            a[r] -= a[l];
            l++;
        }
        else{
            if (c[l] != c[r]){
                ans += a[l];
            }
            l++;
            r--;
        }
    }

    cout << ans << endl;
    return 0;
}
