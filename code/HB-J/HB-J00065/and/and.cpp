#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int arr[N],dp[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    dp[0]=INT_MAX;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            dp[j]=max(dp[j],dp[j-1]&arr[i]);
        }
    }
    cout<<dp[m];
    return 0;
}
