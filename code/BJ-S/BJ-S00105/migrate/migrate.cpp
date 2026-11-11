#include<bits/stdc++.h>
using namespace std;
int c;
long long t,n,d;
long long st[2000005],a[2000005],dp[2000005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","r",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        sort(a+1,a+1+n);
        for(int i = 1;i < n - 1;i++){
            for(int j = i + 1;j <= n;j++){
                st[j] = a[j] - a[i];
            }
            st[i]=0;
            dp[st[i]] = 1;
            dp[st[i+1]] = 1;
            for(int j = i + 2;j <= n;j++){
                if(st[j] < d){
                    for(int k = i;k <= j;k++){
                        dp[st[j]] += dp[k];
                    }
                }
            }
        }
    }
    cout << dp[n] <<endl;
}
