#include<bits/stdc++.h>

using namespace std;

const int N=5e5+5;

long long n,m;
int ans;
long long a[N],prove[N],dp[N];

int main(void)
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    for(int i=1;i<n;i++){
        prove[i]=a[i+1]-a[i];
        dp[i]=dp[i-1]+prove[i];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<=i;j++){
            if(dp[i]-dp[j]<=m)
            {
                ans=max(ans,i-j);
            }
        }
    }

    cout<<ans+1;

    return 0;
}
