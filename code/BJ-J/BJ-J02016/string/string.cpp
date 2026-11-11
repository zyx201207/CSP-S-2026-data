#include <iostream>
#include <algorithm>
#define int long long
#define N 200005
using namespace std;

int n,a[N],ans,m;
char ch[N];
string str;
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i] >> ch[i];
        if(i == 1) m = a[i];
        else m = __gcd(m, a[i]);
    }
    for(int i=1;i<=n;i++) {
        a[i] /= m;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=a[i];j++) {
            str.push_back(ch[i]);
        }
    }
    for(int i=0;i<=str.size()/2;i++) {
        if(str[i] != str[str.size()-i-1]) {
            ans++;
        }
    }
    cout << ans * m;
    return 0;
}
