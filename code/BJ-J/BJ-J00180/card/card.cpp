#include<bits/stdc++.h>
#define long long ll
using namespace std;

int n, m;
int a[500005], ans[500005];;
deque<int> d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i ++)
    {
        set<int> s;
        for(int j = i;j <= n;j ++) {
            if(!s.count(a[j])) {
                d.push_back(a[j]);
                s.insert(a[j]);
            }
            else {
                while(!d.empty()) {
                    d.pop_front();
                }
                s.clear();
                d.push_back(a[j]);
                s.insert(a[j]);
            }
        }
        while(!d.empty()) {
            int r = d.front();
            ans[r] ++;
            d.pop_front();
        }
    }
    for(int i = 1;i <= m;i ++) {
        cout << ans[i] << " ";
    }
    return 0;
}

