#include <bits/stdc++.h>
using namespace std;
bool dp[3005][200005],bottom[3005];
int a[100005],ans[3005],bj[3005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = n - 1;i >= 0;i--){
        if(bottom[a[i]] == 0){
            bottom[a[i]] = 1;
            for(int j = 1;j <= m;j++){
                dp[j][i] = dp[j][i+1];
                if(j == a[i]){
                    dp[j][i] = 1;
                }
                ans[j]+=dp[j][i];
            }
            bj[a[i]] = i;
        }else{
           for(int j = 1;j <= m;j++){
                dp[j][i] = dp[j][bj[a[i]]];
                ans[j]+=dp[j][i];
            }
        }

    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
