#include<bits/stdc++.h>
using namespace std;
const int inf=1e8+20;
int n,m,a[1000005],dp[1005][1005],f[1005][1005],mx=-1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            dp[i][j]=i;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[n];j++){
            int t=i;
            for(int k=1;k<=t;k++){
                dp[i][j+k]=i;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[n];j++){
            for(int k=1;k<=i;k++){
                if(j-a[k]<=m and j-a[k]>=0){
                    dp[i][j]=max(dp[i][j],dp[i][j-a[k]]+k);
                }
            }
        }
    }
    for(int i=1;i<=a[n];i++){
        f[1][i]=i-1;
        if(f[1][i]>m){
            f[1][i]=0;
        }
    }
    for(int i=2;i<=n;i++){
        f[2][i]=f[1][i-1]+f[1][i];
        if(f[2][i]>m){
            f[2][i]=0;
        }
    }
    for(int i=3;i<=n;i++){
        for(int j=1;j<=a[n];j++){
            f[i][j]=f[i-1][j];
            if(f[i][j]>m){
                f[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[n];j++){
            if(f[i][j]!=0){
                if(dp[i][j]>mx){
                    mx=dp[i][j];
                }
            }
        }
    }
    cout<<m;
    return 0;
}
