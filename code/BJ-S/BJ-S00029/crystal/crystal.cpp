#include<bits/stdc++.h>
using namespace std;
long long v[1000005],dp[1000005],n,m,maxn=-1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v,v+n);
    dp[0]=0;
    for(int i=1;i<n;i++){
        if(v[i]==v[i-1]) dp[i]=dp[i-1];
    else dp[i]=dp[i-1]+i*(v[i]-v[i-1]);

        if(dp[i]<=m) maxn=i;
        else {break;}

    }
    cout<<maxn+1;

    return 0;
}
