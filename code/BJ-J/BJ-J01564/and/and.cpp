#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long dp[1000005]={0};
bool used[1000005]={false};
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        long long used1,used2;
        for(int k=0;k<n;k++)
        for(int j=0;j<n;j++)
        {
            if(j==k)
            continue;
            if(used[k]||used[j])
            continue;
            if(a[j]&a[k]>dp[k])
            {
                used1=j;
                used2=k;
                dp[k]=a[j]&a[k];
            }
        }
        used[used1]=true;
        used[used2]=true;
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}