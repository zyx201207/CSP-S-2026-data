#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], cnt[N], wz[N], cnt2[N];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int n1 = 1; n1 <= n; n1++){
        memset(cnt, 0, sizeof(cnt));
        for(int i = n1; i <= n; i++){
            cnt[a[i]]++;
            if(cnt[a[i]] == 2){
                cnt[a[i]]--;
                for(int j = wz[a[i]]; j <= i; j++){
                    cnt[a[j]]--;
                }
            }
            wz[a[i]] = i;
        }
        for(int i = 1; i <= n; i++) cnt2[i] += cnt[i];
    }
    for(int i = 1; i <= n; i++) cout << cnt2[i] << " ";
    return 0;
}
