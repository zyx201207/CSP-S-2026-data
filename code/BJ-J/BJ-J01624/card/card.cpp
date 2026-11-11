#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;

queue<int> q, desk;
int n, m, a[N], b[N], tmps[N];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    int tmp = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        tmp++;
    }
    int st = 0;
    for(int i = 1; i <= n; ++i){

        int wz = 1;
        for(int j = 1; i <= st; ++i) {
            if(a[j] == a[i]) wz = j;
        }
        if(c == 1) {
            a[j] = tmps[j];
        }
    }
    return 0;
}
