#include<bits/stdc++.h>
using namespace std;
long long dp[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<long long> v(1);
    dp[0] = 0xffffffff;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            dp[j] = max(v[i]&dp[j-1],dp[j]);
        }
    }
    cout<<dp[m];
}
