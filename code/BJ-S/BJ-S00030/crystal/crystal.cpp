#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 500005;
int n;
long long m,a[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    long long sum = 0;
    int ans = 0;
    for(int i = 1,ptr = 1;i <= n;i++){
        if(ptr == i){
            ptr++;
        }
        while(ptr <= n && sum + 1LL * (ptr - i) * (a[ptr] - a[ptr - 1]) <= m){
            sum += 1LL * (ptr - i) * (a[ptr] - a[ptr - 1]);
            ptr++;
        }
        ans = max(ans,ptr - i);
        sum -= a[ptr - 1] - a[i];
    }
    cout << ans;
    return 0;
}
