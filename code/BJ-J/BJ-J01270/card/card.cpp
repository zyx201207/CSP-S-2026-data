#include<iostream>
using namespace std;
int n, m, a[50005];
int t[50005];
int ans[50005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            t[a[j]]++;
            if(t[a[j]] >= 2){
                for(int k = 1;k <= n;k++){
                    t[k] = 0;
                }
                t[a[j]] = 1;
            }
        }
        for(int j = 1;j <= n;j++){
            if(t[j] == 1) ans[j]++;
            t[j] = 0;
        }
    }
    for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
    return 0;
}
