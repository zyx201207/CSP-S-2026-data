#include<bits/stdc++.h>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    
    long long n, m, a[200005], ans = 0;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    sort(a, a + n);
    
    ans = a[n];
    
    for(int i = n - 2; i >= n - m; i++){
        ans = ans & a[i];
    }
    
    cout << ans;
    
    
    return 0;
    
}