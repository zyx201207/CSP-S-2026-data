#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],top,ans[300005];
bool num[300005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int t = 0;t < n;t++){
        top = 0;
        fill(num,num + m + 1,0);
        for (int i = t;i < n;i++){
            for (int j = 0;j < top;j++){
                if (b[j] == a[i]){
                    top = j;
                }
            }
            b[top] = a[i],top ++;
        }
        for (int i = 0;i < top;i++) num[b[i]] = 1;
        for (int i = 1;i <= m;i++) if (num[i]) ans[i] ++;
    }
    for (int i = 1;i <= m;i++) cout << ans[i] << ' ';
    return 0;
}

