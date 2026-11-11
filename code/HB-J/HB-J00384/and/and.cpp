#include <bits/stdc++.h>
using namespace std;

priority_queue <long long> q;
int n, m;
long long a;
long long ma = 0;

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a;
        q.push(a);
    }
    ma = q.top();
    q.pop();
    for (int i = 1; i < m; i++){
        ma &= q.top();
        q.pop();
    }
    cout << ma;
    return 0;
}
