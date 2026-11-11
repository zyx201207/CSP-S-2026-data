#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
struct NODE{
    int val;
    char c;
}a[N];
long long sum;
int main() {
     freopen("string.in", "r", stdin);
     freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1;i  <= n; i++) {
        cin >> a[i].val >> a[i].c;
        sum += a[i].val;
    }
    long long now = 0;
    long long ans = 0;
    for (int l = 1, r = n; l <= n;) {
        //cout << l << ' ' << r << ' ' << ans <<  ' ';
        if (l  > r) break;
        if (now <= sum / 2) {
            if (a[l].val < a[r].val) {
                if (a[l].c == a[r].c) {
                    a[r].val -= a[l].val;
                    now += a[l].val;
                    l++;
                    
                }
                else if (a[l].c != a[r].c ){
                    ans += a[l].val;
                    a[r].val -= a[l].val;
                    now += a[l].val;
                    l++;
                    
                }
                
            }
            else if (a[l].val > a[r].val) {
                if (a[l].c == a[r].c) {
                    a[l].val -= a[r].val;
                    now += a[r].val;
                    r--;
                    
                }
                else if (a[l].c != a[r].c ){
                    now += a[r].val;
                    ans += a[r].val;
                    a[l].val -= a[r].val;
                    r--;
                    
                }
            }
            else if (a[l].val == a[r].val) {
                if (a[l].c == a[r].c) {
                    now += a[r].val;
                    a[l].val = 0, a[r].val = 0;
                    l++,r--;
                    
                    
                }
                else if (a[l].c != a[r].c ){
                    now += a[r].val;
                    ans += a[r].val;
                    //cout << a[r].val << endl;
                    a[l].val = 0, a[r].val = 0;
                    l++,r--;
                    
                }
            }
        } else break;
    }
    cout << ans;
    return 0;
}