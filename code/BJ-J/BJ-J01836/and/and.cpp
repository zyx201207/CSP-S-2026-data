#include<bits/stdc++.h>
using namespace std;
long long a[200005],dp[200005];
long long n,m;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long max_pos=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>a[max_pos])max_pos=i;
    }
    dp[1]=a[max_pos];
    a[max_pos]=-1;
    for(int i=2;i<=n;i++){
        max_pos=0;
        while(a[max_pos]==-1)++max_pos;
        long long maxn=dp[i-1]&a[max_pos];
        for(int j=max_pos+1;j<=n;j++){
            if(dp[i-1]&a[j]>maxn&&a[j]!=-1)max_pos=j;
        }
        dp[i]=dp[i-1]&a[max_pos];
        a[max_pos]=-1;
    }
    cout<<dp[m];
}
