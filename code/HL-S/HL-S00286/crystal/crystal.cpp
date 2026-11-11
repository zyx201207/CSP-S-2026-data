#include <bits/stdc++.h>

using namespace std;
int n;
long long m;
long long dp[500010];
long long arr[500010];
int maxn;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++) cin >>arr[i];
    sort(arr+1,arr+n+1);
    for(int i=2;i<=n;i++){
        dp[i]=(arr[i]-arr[i-1])*(i-1)+dp[i-1];
        if(dp[i]<=m){
            int result=i;
            if(result>=maxn){
                maxn=result;
            }
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dp[j]=dp[j]-(arr[j]-arr[i-1]);
            if(dp[j]<=m){
                int result=j-i+1;
                if(result>=maxn){
                    maxn=result;

                }
            }
        }
    }
    cout <<maxn;
	return 0;
}
