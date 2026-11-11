#include<bits/stdc++.h>
using namespace std;

int n,m,a[200010];
long long dp[200010];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        dp[i]=a[0];
    }
    for(int i=0;i<n;i++){
        for(int j=m;j>=1;j--){
            long long x=dp[j-1]&a[i];
            dp[j]=max(dp[j],x);
        }
    }
    cout<<dp[m];
    return 0;
}
