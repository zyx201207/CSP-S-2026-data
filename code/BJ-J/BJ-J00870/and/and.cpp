#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N=2e5+5;
int a[N];
int dp[N];
int n,m,ans=-1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[0]=-1;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
            dp[j]=max(dp[j],dp[j-1]&a[i]);
    cout<<dp[m];
    return 0;
}
