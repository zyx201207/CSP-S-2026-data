#include <bits/stdc++.h>
#define int long long
using namespace std;
int n = 0;
int c = 0;
int t = 0;
int d = 0;
int x[2000010];
int R[2000010];
int L[2000010];
int sl[2000010];//前缀和
int sr[2000010];//后缀和
pair <int,int> segr[2000010];
pair <int,int> segl[2000010];
int kn[2000010];
void solve(){
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> x[i];
    //先求L,L[n]用不到
    L[1] = 1;sl[1]=1;
    for(int i = 2; i < n; i++){
        L[i] = 1;
        int l = 1; int r = i - 1;
        int p1 = -1; int p2 = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(x[i] - x[mid] <= d){
                p1 = mid; r = mid - 1;
            }
            else l = mid + 1;
        }
        l = 1; r = i - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(x[i + 1] - x[mid] > d){
                p2 = mid; l = mid + 1;
            }
            else r = mid - 1;
        } // p1~p2这部分是可以跳的
        if(p1 != -1 && p2 != -1){
            L[i] += sl[p2] - sl[p1 - 1];
        }
        sl[i] += L[i]; sl[i] += sl[i -1];
        segl[i] = {p1, p2};
    } R[n] = 1; sr[n] = 1;

    for(int i = n - 1; i > 1; i--){
        R[i] = 1;
        int l = i + 1; int r = n;
        int p1 = -1; int p2 = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(x[mid] - x[i] <= d){
                p1 = mid; l = mid + 1;
            }
            else r = mid - 1;
        }
        l = i + 1; r = n;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(x[mid] - x[i - 1] > d){
                p2 = mid; r = mid - 1;
            }
            else l = mid +1;
        } // p2~p1这部分是可以跳的
        if(p1 != -1 && p2 != -1){
            R[i] += sr[p2] - sr[p1 + 1];
        }
        sr[i] += R[i]; sr[i] += sr[i + 1];
        segr[i] = {p2, p1};
    } int ans = 0;
 /*   for(int i = 1; i <= n; i++){
        cout << L[i] << " ";
    } cout << '\n';
    for(int i = 1; i <= n; i++){
        cout << R[i] << " ";
    } cout << '\n';
    for(int i = 1; i <= n; i++){
        cout << sl[i] << " ";
    } cout << '\n';
    for(int i = 1; i <= n; i++){
        cout << sr[i] << " ";
    } cout << '\n';
*/
    for(int i = n - 2; i >= 2; i --){
        if(i <= n - 4){
            int l = i + 2; int r = n - 2;
            int ps = -1;
            while(l <= r){
                int mid = (l + r) >> 1;
                if(x[mid] - x[i] <= d){
                    ps = mid; l = mid + 1;
                } else r = mid - 1;
            }
            if(ps != -1){
                if(x[ps] >= d+x[i-1]+1 && x[ps+1] <= d+x[i+1] && x[ps+1]>=d+x[i]+1){
                    kn[i] += kn[ps];
                    //cout << i << " " << ps << "\n";
                }
            }
        }

        if(segr[i].first != -1 && segr[i].second != -1){
            int _l = max(i+2,segr[i].first); int _r=segr[i].second;
            kn[i] += sr[_l]-sr[_r+1];
            if(i == 3){
                //cout << i << " " << kn[i] << '\n';
                //cout << _l <<" " << _r << '\n';
            }
        }
        //cout << i << " " << kn[i] << '\n';
        if(segl[i+1].first!=-1&&segl[i+1].second!=-1){
            int _l = segl[i+1].first; int _r = min(i-1,segl[i+1].second);
            ans += kn[i] * (sl[_r]-sl[_l-1]);
        }
    }
    for(int i = 1; i <= n; i++){
        kn[i] = 0;
        x[i] = 0; L[i] = 0; R[i] = 0; sl[i] = 0; sr[i] = 0;
        segl[i].first = 0; segl[i].second = 0;
        segr[i].first = 0; segr[i].second = 0;

    }
    cout << ans << '\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("migrate.in", "r",stdin);
    freopen("migrate.out", "w",stdout);
    cin >> c >> t;
    while(t --){
        solve();
    }
    return 0;
}
