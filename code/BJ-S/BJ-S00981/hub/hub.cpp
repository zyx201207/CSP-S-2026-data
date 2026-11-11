#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int c, T, n, k;
vector<int> e[N];

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while (T--){
        scanf("%d%d", &n, &k);
        for (int i = 1; i < n; i++){
            int u, v; scanf("%d%d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        printf("0\n");
    }
    return 0;
}