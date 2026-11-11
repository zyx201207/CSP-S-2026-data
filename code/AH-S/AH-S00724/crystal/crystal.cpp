#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10;
int n,m,a[N];
unsigned dp[5000][N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<=m;i++){
        dp[0][i]=1ll;
    }
    for(int i=1;i<=m+1;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=1;
            for(int k=1;k<=1;k++){
                int t=a[j]-a[j-k];
                if(t*k<i){
                    dp[i][j]=max(dp[i][j],dp[i-t*k-1][j-k]+1);
                }
            }
        }
    }
    int ma=0;
    for(int i=1;i<=m+1;i++){
        for(int j=1;j<=n;j++){
            if(ma<dp[i][j])ma=dp[i][j];
        }
    }
    cout<<ma<<endl;
    return 0;
}

