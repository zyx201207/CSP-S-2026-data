#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n;// wei shen me xie bu liao zhongwen!!!!
long long m, zw;
long long a[N];
long long b[N];
int c[N];
#define int long long
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i]!=i){
            flag = false;
        }
        
    }
    
    sort(a + 1, a + n + 1);
    int maxx = a[n];
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur +=a[n] - a[i];
         if (a[i] != a[i - 1]) {
            b[i] = a[i - 1];
            c[i] = i - 1;
         }
         else {
            b[i] = b[i - 1];
            c[i] = c[i - 1];
         }
    }
    int ans = 0;
    int l = 1, r = n, nmax = a[n];
    while(cur > m) {
        int right = (a[r] - a[l]) * (r -l - (r - c[r]));
        int left = (a[r] - a[l]); //cout << cur << endl;
        if (left < right) {
            //cout << "Case1\n";
           // cout << "delete r\n" << l << " " << r-1;cout << '\n';
            cur -= (a[r] - a[r- 1]) * (r -l - (r - c[r] - 1));
            // if ((a[r] - a[r- 1]) * (r -l - (r - c[r] - 1)) > a[r - 1] - a[l - 1]) {
            //     l--;
            //     cur += a[r - 1] - a[l];
            // }
            r--;
            //cout << cur;
            
            //cout << r + 1 << " " << c[r + 1] << endl;
            ans++;
        }
        if (left > right) {
           // cout << "delete l\n" << l + 1 << " " << r;cout << '\n';
            // if ((a[r] - a[l]) * (r -l - (r - c[r] - 1)) > a[r - 1] - a[l - 1]) {
            //     l--;
            //     r--;
                
            //     cur += a[r - 1] - a[l];
            // }
            cur -= a[r] - a[l];l++;
            ans++;
        }
        if (left == right) {//cunyi
            if (a[r] - a[l] > (a[r] - a[l]) * (r -l)){
            //    cout << "delete l\n" << l + 1 << " " << r;
            //    cout << '\n';
                cur -= a[r] - a[l];
                l++;
            }
            else{
            //    cout << "delete r\n" << l  << " " << r - 1;cout << '\n';
                cur -= (a[r] - a[r - 1]) * (r -l);
                r--;
            }
            ans++;
        }
    }
    cout << r - l + 1;
    return 0;
}