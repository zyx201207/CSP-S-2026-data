# include <bits/stdc++.h>
using namespace std;
# define int long long
const int N = 2e5+5;
int a[N], b[N];

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }

    for (int j=30;j>=0;j--){
        int t = (1 << j), cnt = 0;
        for (int i=1;i<=n;i++){
            if (b[i] == 1) continue ;
            if ((a[i] & t) == t){
                cnt++;
            }
        }

        if (cnt >= m){
            for (int i=1;i<=n;i++){
                if ((a[i] & t) == 0){
                    b[i] = 1;
                }
            }
        }

    }

    int ans = -1, cnt = 0;
    for (int i=1;i<=n;i++){
        if (b[i] == 0){
            if (ans == -1) ans = a[i];
            else ans = (ans & a[i]);
            cnt++;
        }
        if (cnt == m) break;
    }
    cout << ans << endl;
    return 0;
}
