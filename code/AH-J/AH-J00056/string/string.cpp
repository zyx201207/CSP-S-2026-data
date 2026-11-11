#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int cnt;
int diffl, diffr;
int n;
int a[N];
char op[N];
int sum;
int alsum;

signed main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i] >> op[i];
        alsum += a[i];
    }
    alsum /= 2;
    int l=1, r=n;
    while(l<=r) {
        diffl += a[l];
        diffl = min(diffl, alsum);
        diffr += a[r];
        diffr = min(diffr, alsum);
        int t1 = diffl - sum;
        int t2 = diffr - sum;
        if(op[l] != op[r]) {
            cnt += min(t1, t2);
        }
        sum += min(t1, t2);
        int tmp = min(t1, t2);
        t1 -= tmp;
        t2 -= tmp;
        if(t1 == 0) l++;
        if(t2 == 0) r--;
        if(sum==alsum) break;
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}







