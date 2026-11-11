#include <bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int n,m,a[maxn],ans[maxn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            if (a[j]==i){
                ans[i]++;
            }
        }
    }
    for (int i=1;i<=m;i++){
        if (i==a[n]){
            cout << n << " ";
        }
        else{
            cout << ans[i] << " ";
        }
    }
    return 0;
}
