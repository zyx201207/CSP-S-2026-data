#include<bits/stdc++.h>
using namespace std;
int n;
//n 个连续的段;
int a[200010];
bool w[1010][1010];
//a 个小写英文字母c
string c[200010];
int dp[1010][1010];
signed main(){
    cin>>n;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
        w[i][i]=1;
        if(c[i]==c[i+1]){
            dp[i+1][i]=0;
            w[i+1][i]=1;
        }else{
            if(a[i]==a[i+1]){
                dp[i+1][i]=a[i];
                w[i+1][i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<w[i][j]<<" ";
        }cout<<endl;
    }
    for(int i=2;i<=n;i++){//3 1
        for(int j=i-1;j>=1;j--){
            if(w[i][j]==0){
                if(c[i]==c[j]){
                    if(a[i]==a[j]){
                        dp[i][j]=dp[i-1][j+1];
                    }else{
                        if(a[j]==0){
                            dp[i][j]=dp[i-1][j];
                        }else{
                            dp[i][j]=dp[i][j+1];
                        }
                    }
                }else{
                    if(a[i]==a[j]){
                        dp[i][j]=dp[i-1][j+1]+a[i];
                    }else{
                        if(a[j]==0) dp[i][j]=dp[i-1][j]+min(a[i],a[j]);
                        else dp[i][j]=dp[i][j+1]+min(a[i],a[j]);
                    }
                }
            }

        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    cout<<dp[n][1];
    return 0;
}
