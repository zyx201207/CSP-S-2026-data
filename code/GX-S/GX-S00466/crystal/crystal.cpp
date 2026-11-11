#include<bits/stdc++.h>
using namespace std;
long long arr[500009]={0};
long long b[500009]={0};
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    sort(arr+1,arr+n+1);
    int ans=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<i;j++)
            b[i]+=arr[i]-arr[j];
        if(b[i]<=m)
        {
            ans=i;
            break;
        }
    }
    cout<<ans;
    return 0;
}
