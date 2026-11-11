#include <bits/stdc++.h>
using namespace std;

int n, m, a[200000], ans=0;

void dfs(int pos, int cnt, int s) {
    if(cnt == m) {
        if(s > ans) {
            ans=s;
        } else {
            return;
        }
    }
    if(pos==n) {
        return;
    }
    dfs(pos+1, cnt, s);
    int ns = s & a[pos+1];
    dfs(pos+1, cnt+1, ns);
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int i;
    scanf("%d%d", &n, &m);
    for(i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
    }
    if(m==n) {
        ans=a[1];
        for(i=2; i<=n; ++i) {
            ans=ans&a[i];
        }
    } else if(m==1) {
        sort(a, a+n-1);
        ans=a[n];
    } else {
        for(i=1; i<=n-m+1; ++i) {
            dfs(i, 1, a[i]);
        }        
    }

    printf("%d", ans);
    return 0;
}