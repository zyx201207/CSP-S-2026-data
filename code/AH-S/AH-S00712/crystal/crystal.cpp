#include<bits/stdc++.h>
using namespace std;
int a[500005];
long long dp[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[1]=1;
    for(long long i=2;i<=n;i++){
        long long l=m;
        long long j=i-1;
        while(l>0&&j>0){
            if(l-(a[i]-a[j])>=0){
                l-=(a[i]-a[j]);
                j--;
            }else{
                break;
            }
        }j++;
        dp[i]=max(dp[i-1],i-j+1);
    }
    cout<<dp[n];
   return 0;
}
