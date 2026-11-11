#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+2;
int n,m;
ll dp[N];
unsigned long long a[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        //a[i]=a;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            if(j==1)
            {
                dp[j]=max(dp[j],(ll)a[i]);
            }
            else dp[j]=max(dp[j],dp[j-1]&(ll)a[i]);
        }
    }
    cout<<dp[m];
    return 0;
}
