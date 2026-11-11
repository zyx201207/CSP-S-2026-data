#include<bits/stdc++.h>

using namespace std;
long long c, t, n, d, x[2000010], step[2000010];
map<long long, long long> mp;
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        long long cnt = 0;
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> x[i];
        for(int k = 1; k <= n; k++){
            memset(step, 0x3f, sizeof step);
            step[k] = 0;
            for(int i = k; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                    if(x[j] <= x[i] + d){
                        if(step[j] > step[i] + 1){
                            step[j] = step[i] + 1;
                            mp[j] = 1;
                        }else if(step[j] == step[i] + 1){
                            mp[j]++;
                        }
                    }
                    else break;
                }
            }
            for(int i = k; i <= n; i++){
                if(mp[i] == 2){
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
