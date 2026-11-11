#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+10;
const int MAXM = 3e5+10;
bool used[MAXM];
int a[MAXN],ans[MAXM];

int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int q[MAXN],now = -1;
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n;i++) {
        scanf("%d",&a[i]);
    }
    for (int i = 0;i < n;i++) {
        memset(used,0,sizeof used);
        for (int j = i;j < n;j++) {
            if (used[a[j]]) {
                while (q[now] != a[j]) {
                    used[q[now]] = 0;
                    q[now--] = 0;
                }
            } else {
                q[++now] = a[j];
                used[a[j]] = 1;
            }
        }
        while (q[0] != 0) {
            ans[q[now]]++;
            q[now--] = 0;
        }
    }
    for (int i = 1;i <= m;i++) printf("%d ",ans[i]);
    return 0;
}
