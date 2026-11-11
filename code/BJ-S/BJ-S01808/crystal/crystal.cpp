#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],dp[N],sum[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    dp[n]=0;
    sum[n]=0;
    ll st=n;
    for(int i=n;i>=1;i--){
        if(sum[n]+a[n]-a[i]<=m){
            sum[n]+=a[n]-a[i];
            dp[n]++;
            st--;
        }else break;
    }
    for(int i=n-1;i>=1;i--){
        dp[i]=dp[i+1]-1;
        sum[i]=sum[i+1]-dp[i]*(a[i+1]-a[i]);
        while(st>=1){
            if(sum[i]+a[i]-a[st]<=m){
                sum[i]+=a[i]-a[st];
                dp[i]++;
                st--;
            }else break;
        }
    }
    ll maxn=0;
    for(int i=1;i<=n;i++)maxn=max(maxn,dp[i]);
    cout<<maxn<<endl;
    return 0;
}
