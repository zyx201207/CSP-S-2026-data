#include <bits/stdc++.h>
#define N 200011
using namespace std;

int n, m;
int a[N];
int cnt[N], ans[N];
int sta[N], top;

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];



    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cnt[j] = 0;
        top = 0;
        for(int j = i; j <= n; j++)
            if(cnt[a[j]] == 1)
                while(top != 0 && sta[top] != a[j])
                    cnt[sta[top--]] = 0;
            else {
                cnt[a[j]]++;
                sta[++top] = a[j];
            }
        while(top != 0)
            ans[sta[top--]]++;
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}