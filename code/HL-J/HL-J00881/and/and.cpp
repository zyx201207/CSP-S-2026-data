#include <iostream>
#include <vector>
#include <queue>

using namespace std;
priority_queue<int> Q;
vector<int> vec;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);


    int n, m;
    int x;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        Q.push(x);
    }

    int ans = Q.top();
    Q.pop();
    for (int i = 1; i <= (m - 1); i++) {
        int x = Q.top();
        Q.pop();
        ans = ans & x;
    }

    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

