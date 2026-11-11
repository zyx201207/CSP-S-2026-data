#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long dp[5005][5005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
            f=0;
        }
    }
    if(f){
        long long ch=a[2]-a[1];
        long long now=0;
        for(int i=1;i<=n;i++){
            now=(i-1)*ch+now;
            if(now>m){
                cout<<i-1;
                return 0;
            }
//            cout<<now<<endl;
        }
        cout<<n;
        return 0;
    }
    else{
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
//                cout<<i<<' '<<a[i]<<' '<<j<<' '<<a[i-1]<<endl;
//                cout<<a[i]-a[i-1]<<endl;
                dp[i][j]=dp[i-1][j-1]+(a[i]-a[i-1])*j;
                if(dp[i][j]<=m){
                    ans=max(ans,j+1);
                }
            }
        }
/*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<dp[i][j]<<' ';
            }
            cout<<endl;
        }
*/
        cout<<ans;
    }
    return 0;
}
