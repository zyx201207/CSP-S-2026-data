#include<bits/stdc++.h>
using namespace std;
#define int long long
int check(int a,int b){
        if(!a)return b;
        if(!b)return a;
        return (a & b);
}
int dp[10000010];
int ls[10000010];
signed main(){
        freopen("and.in","r",stdin);
        freopen("and.out","w",stdout);
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n,m,maxn = 0;
        cin >> n >> m;
        for(int i = 1;i <= n;i++){
            cin >> ls[i];
            maxn = max(maxn,ls[i]);
        }
        if(n * m >= 1000000000){
			cout << maxn;
			return 0;
		}
        for(int i = 1;i <= n;i++){
			for(int j = m;j >= 1;j--){
				dp[j + 1] = max(dp[j + 1],check(dp[j],ls[i]));
			}
		}
        cout << dp[m];
}
