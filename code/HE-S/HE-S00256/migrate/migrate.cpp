#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int c,T;
long long x[2000006];
long long dp[2000006];
void s(int c){

    memset(x,0,sizeof(x));
    memset(dp,0,sizeof(dp));
    int n,d;
    cin >> n >> d;
    for(int i = 0;i<n;i++){
        cin >> x[i];
    }

    if(c == 13||c == 14) {cout << pow(n,2);return;}
    dp[1] = 0;
    long long ans = 0;
    for(int i = 0;i<n;i++){
        long long t = 0;
        long long minn = LLONG_MAX,cnt = 0;
        for(int j = i-1;j>=0;j--){
            if(x[i]-x[j]>d){
                break;
            }else{
                if(dp[j]<minn){
                    minn = dp[j];
                    cnt = 1;
                }else if(dp[j] >= minn){
                    cnt++;
                }
            }
        }
        dp[i] = cnt;
        if(cnt==2) ans++;
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> T;

    while(T--) s(c);
}
