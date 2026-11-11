#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[500005];//what is the number on card (i)
int vis[300005];//where is the card that its number is (i)
int ans[300005];//the answer
//vis[a[i]] means: where is the No.(i) card

int main() {
    freopen("card2.in","r",stdin);
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    for (int i=1;i<=n;i++) {
        memset(vis,0,sizeof(vis));
        cnt = 0;
        for (int j=i;j<=n;j++) {
            cnt++;
            if (vis[a[j]] != 0) {
                for (int k=vis[a[j]]+1;k<=j;k++) {
                    vis[a[k]] = 0;
                    cnt--;
                }
            }
            else {
                vis[a[j]] = cnt;
            }
        }
        for (int j=1;j<=n;j++) {
            if (vis[a[j]]) ans[a[j]]++;
            vis[a[j]] = 0;
        }
    }
    for (int i=1;i<=m;i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
