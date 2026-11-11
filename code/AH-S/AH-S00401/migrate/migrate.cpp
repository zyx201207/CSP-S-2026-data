#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans,f;char c;
inline ll read(){
    ans = 0;f = 1;char c;
    c = getchar();

    while(c < '0' || c > '9'){
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ans = 10*ans + c-'0';
        c = getchar();
    }
    return ans*f;
}
ll cc,t;
ll n,d,res,lis[2000005],dp[2000005],cnt[200005];

void sol(){
    n = read();d =read();
    for(int i = 1;i <= n;i++) lis[i] = read();

    res = 0;
    for(int i = 1;i <= n;i++){
        memset(dp,0x3f,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        dp[i] = 0;

        for(int j = i;j <= n;j++){
            for(int k = j-1;k >= i;k--){
                if(lis[j]-lis[k] <= d){
                    if(dp[k]+1 == dp[j]) cnt[j]++;
                    else if(dp[k]+1 < dp[j]){
                        dp[j] = dp[k]+1;
                        cnt[j] = 1;
                    }
                }
                else break;
            }
        }

        for(int k = i;k <= n;k++) res += (cnt[k] == 2) ? 1:0;
    }

    cout << res << '\n';
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin >> cc >> t;
    while(t--) sol();

    fclose(stdin);fclose(stdout);
    return 0;
}
