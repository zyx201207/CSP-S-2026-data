#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m; cin >> n >> m;
    int val = INT_MAX;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i]; val = val & a[i];
    }
    if(m == 1) cout << *max_element(a.begin(), a.end());
    else if (m == n) cout << val;
    else if(m == n-1){
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans, ~(val ^ a[i]));
        }
        cout << ans;
    }
    else {
        sort(a.begin(), a.end());


        
        int c = (int)log2((double) n); int cnt=1;
        while(m > c){
            c += c * cnt;
            cnt * 2;
        }
        cout << max(a[n-m], n - (1 << cnt));
        return 0;

    }

    return 0;

}
