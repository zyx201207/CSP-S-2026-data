#include <bits/stdc++.h>
using namespace std;
int n,m;
long long k = 1,maxn = 0;
long long a[200005];
long long dp[1000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < m;i++){
        k *= (n-i);
        k /= (i+1);
    }
    long long cnt =2,num = 1;
    for(int i = 1;i <= k;i++){
        if(num == n-1 && cnt == n+1) break;
        if(cnt == n+1){
            num++;
            cnt = num + 1;
        }
        dp[i] = a[num] & a[cnt];
        cnt++;
    }
    for(int i = 1;i <= k;i++){
        maxn = max(maxn,dp[i]);
    }
    cout << maxn;
    return 0;
}
