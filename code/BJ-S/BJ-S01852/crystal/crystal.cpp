#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    sum[0]=0;
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    //for(int i=1;i<=n;i++) cout<<sum[i]<<" ";
    //cout<<endl;
    int l=1,r=1,ans=0;
    //for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    while(l<=r&&r<=n)
    {
        ans=max(ans,r-l+1);
        //cout<<l<<" "<<r<<endl;
        //cout<<(r-l+2)<<" "<<a[r+1]<<" "<<sum[r+1]-sum[l-1]<<endl;
        if((r-l+2)*a[r+1]-sum[r+1]+sum[l-1]<=m) r++;
        else l++;
        //cout<<l<<" "<<r;
        //getchar();
    }
    cout<<ans;
    return 0;
}
