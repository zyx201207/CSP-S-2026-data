#include<bits/stdc++.h>
#define int long long
using namespace std;
int arr[500005];
int sum[500005];
int get_sum(int l,int r)
{
    return sum[r]-sum[l-1];
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,ans=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    sort(arr+1,arr+1+n);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+arr[i];
    for(int i=1,j=1;j<=n;)
    {
        if(arr[j]*(j-i+1)-get_sum(i,j)>m)i++;
        else
        {
            ans=max(ans,j-i+1);
            j++;
        }
    }
    cout<<ans;
    return 0;
}
