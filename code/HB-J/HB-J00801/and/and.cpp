#include<bits/stdc++.h>
using namespace std;
long long int a[200005];
long long int dp[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int k=0;
    long long int ans=1;
    int t=0;
    while(k<=31)
    {
        k++;
        ans*=2;
        if(ans==a[n]) t=1;
    }
    int j=n;
    if(t==1) j=n-1;
    dp[1]=a[j];
    for(int i=1;i<=m;i++)
    {
        j--;
        dp[1]&=a[j];
    }
    for(int i=1;i<=m;i++)
    {
        for(int w=1;w<=n;w++)
        {
            dp[i]=max(dp[i],dp[i-1]&a[w]);
        }
    }
    cout<<dp[m];
    return 0;
}