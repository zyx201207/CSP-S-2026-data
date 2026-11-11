#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt[300007],ans[300007],a[500007];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++)cnt[j] = 0;
        for(int j = i;j <= n;j++){
            cnt[a[j]]++;
            if(cnt[a[j]] == 2){
                for(int k = j - 1;;k--){
                    if(a[k] == a[j]){
                        cnt[a[j]]--;
                        break;
                    }
                    cnt[a[k]]--;
                }
            }
        }
        for(int j = 1;j <= m;j++)ans[j] += cnt[j];
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
