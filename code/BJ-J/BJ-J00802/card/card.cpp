#include<iostream>
#include<cstring>
#define MAXN 500009
using namespace std;
int n, m, a[MAXN], ans[MAXN];
int desk[MAXN], cnt;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
//    for(int i = 1; i <= n; i++)
//        cout << a[i] << " ";
    for(int i = 1; i <= n; i++) { //everyGame
        memset(desk, 0, sizeof desk);
        cnt = 0;
        for(int j = i; j <= n; j++) { //everyCard
            int k = a[j];
            for(int p = 1; p <= cnt; p++) {
                if(desk[p] == k) {
                    for(int s = p; s <= cnt; s++)
                        desk[s] = 0;
                    cnt = p - 1;
                    break;
                }
            }
            cnt++;
            desk[cnt] = k;
        }
        for(int j = 1; j <= cnt; j++)
            ans[desk[j]]++;
    }
    for(int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    return 0;
}
