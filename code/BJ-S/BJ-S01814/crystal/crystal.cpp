#include<bits/stdc++.h>
using namespace std;
int n;
long long m,maxlen;
long long a[500005],s[500005];
long long dp[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(long long len=1;len<=n;len++){
        dp[len]=INT_MAX;
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            dp[len]=min(dp[len],a[j]*len-s[j]+s[i-1]);
        }
        if(dp[len]<=m){
            maxlen=max(maxlen,len);
        }
        else if(dp[len-2]>m){
            break;
        }
    }
    cout<<maxlen;
    return 0;
}
