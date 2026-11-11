#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[200011];
int ans;
vector<int> v;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }
    for(int i = 30; i >= 0; i--) {
        vector<int> tmp;
        for(auto x : v) {
            if((x >> i) & 1) 
                tmp.push_back(x);
        }
        if(tmp.size() >= m) {
            v = tmp;
        }
    }
    ans = (1 << 30) - 1;
    for(auto x : v) {
        ans &= x;
    }
    printf("%d\n", ans);
    return 0;
}