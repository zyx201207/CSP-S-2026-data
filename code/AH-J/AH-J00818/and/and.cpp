#include<bits/stdc++.h>
using namespace std;
int a[200005],dp[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    dp[1]=a[n];
    for(int i=1;i<n;i++)
        for(int j=m;j>=1;j--)
            dp[j]=max(dp[j],dp[j-1]&a[i]);
    cout<<dp[m];
    return 0;
}
