#include<bits/stdc++.h>
using namespace std;
int dp[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a[200005];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=m;j>i;j--){
            int f=a[i]&a[j];
            dp[j]=max(dp[j],dp[j]+f);
        }
    }
    cout<<dp[m];
    return 0;
}
