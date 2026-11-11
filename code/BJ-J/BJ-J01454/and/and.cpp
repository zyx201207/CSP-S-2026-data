#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;
int a[MAXN];
int n,m;

int mx = 0;
void dfs(int step,int now,int idx) {
    if (step == 0) {
        mx = max(mx,now);
        return;
    } else if (idx == n-1) return;
    for (int i = idx;i <= n-step;i++) {
        dfs(step-1,now & a[i],i+1);
    }
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n;i++) {
        scanf("%d",&a[i]);
    }
    dfs(m,INT_MAX,0);
    printf("%d",mx);
    return 0;
}
