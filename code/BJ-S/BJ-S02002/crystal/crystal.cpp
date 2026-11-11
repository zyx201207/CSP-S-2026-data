#include<bits/stdc++.h>
using namespace std;
const long long N = 1e6+5;
long long n, m, l;
int a[N],b[N];
long long ma,ans;
long long check(int x, int m){
    for(int i = x;i <= n; i++){
        if(l <= m && (l + b[x] - b[i]) <= m){
            l += b[x] - b[i];
            ans++;
        }
    }
    return ans;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i=1;i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i=1;i <= n; i++){
        b[n-i+1] = a[i];
    }
    for(int i=1; i <= n; i++){
        l = 0;
        ans = 0;
        check(i, m);

        ma = max(ans, ma);
    }
    cout << ma ;
    return 0;
}
