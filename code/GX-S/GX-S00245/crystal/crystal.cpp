#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],dp[10000][10000],ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        bool flag=false;
        long long minn=INT_MAX;
        for(int j=i;j<=n;j++){
            dp[i][j]=dp[i-1][j-1]+(a[i]-a[i-1])*(i-1);
            if(dp[i][j]<=m){
                ans=i;
                minn=min(minn,dp[i][j]);
                flag=true;
            }
        }
        if(flag&&minn==m)
            break;
        if(flag==false)
            break;
    }
    cout<<ans<<endl;
    return 0;
}
