#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int ans;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        pq.push(x);
    }
    ans = pq.top(); pq.pop();
    for(int i = 1; i <= m-1; i++){
        int x = pq.top(); pq.pop();
        ans = ans & x;
    }
    cout << ans << '\n';
    return 0;
}