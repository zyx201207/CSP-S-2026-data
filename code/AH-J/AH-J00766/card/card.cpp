//Eason Cyj001001 AH-J00766
#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int a[N];
int n,m;
int t[N];
int ans[N];
int dp[N];
int flag[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        t[a[i]] = i;
    }
    for(int i=1; i<=n; i++) {
        if(flag[i]) continue;
        int p=0;
        for(int j=i; j<=n; j++) {
            if(p==0){ans[a[j]] ++;j = t[a[j]];}
            else{
                if(flag[j]==true) {
                    ans[a[j]] ++;j = t[a[j]];
                }else{
                    ans[a[j]] ++;j = t[a[j]];
                    ans[a[j]] ++;flag[j] = true;
                }
            }

        }
    }
    for(int i=1; i<=m; i++) cout << ans[i] << " ";
    return 0;
}
