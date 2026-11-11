#include<bits/stdc++.h>
using namespace std;
long long MAXN = 2000000000010LL;
long long s[500010];
bool f[500010];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    long long m;
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &s[i]);
        f[i] = false;
    }
    if(n == 1){
        printf("1");
        return 0;
    }
    sort(s + 1, s + n + 1);
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(f[i] == false && s[i + 1] - s[i] <= m){
            int l = i;
            int r = i + 1;
            long long xp = s[r];
            long long v = m;
            f[l] = f[r] = true;
            while(v > 0){
                long long s1 = MAXN;
                long long s2 = MAXN;
                if(l > 1){
                    s1 = xp - s[l - 1];
                }
                if(r < n){
                    s2 = (r - l + 1) * (s[r + 1] - xp);
                }
                if(s1 <= s2){
                    if(v >= s1){
                        l--;
                        f[l] = true;
                        v -= s1;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(v >= s2){
                        r++;
                        f[r] = true;
                        xp = s[r];
                        v -= s2;
                    }
                    else{
                        break;
                    }
                }
            }
            ans  = max(ans, r - l + 1);
        }
    }
    printf("%d", ans);
    return 0;
}
