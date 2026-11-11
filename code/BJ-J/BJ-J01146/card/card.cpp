#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[6666];
int dp[6666][6666];
int nxt[6666];
int sss[6666];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for (int i = n;i>=1;i--){
        nxt[i] = sss[a[i]];
        sss[a[i]] = i;
    }
    //cout<<n<<endl;
    for (int i = n;i>=1;i--){
        //cout<<i<<endl;
        if (nxt[i]==0){
            for (int j = 1;j<=m;j++){
                dp[i][j] = dp[i+1][j];
            }
            dp[i][a[i]] = 1;
        }else{
            for(int j = 1;j<=m;j++){
                dp[i][j] = dp[nxt[i]][j];
            }
        }
    }
    for (int i = 1;i<=m;i++){
        int cnt = 0;
        for (int j = 1;j<=n;j++){
            cnt+=dp[j][i];
        }
        cout<<cnt<<" ";
    }
    return 0;
}
