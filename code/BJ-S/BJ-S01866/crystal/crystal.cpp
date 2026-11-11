#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,sum,a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int l=1,r=1;r<=n;r++)
    {
        sum+=(a[r]-a[r-1])*(r-l);
        while(sum>m)
        {
            sum-=a[r]-a[l++];
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}