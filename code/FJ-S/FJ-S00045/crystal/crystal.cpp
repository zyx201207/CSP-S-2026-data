/*
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1145140],k,sum[1145140],ans;
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    k=1;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    k=1;
    for(int i=1;i<=n;i++)
    {
        while(((i-k+1)*a[i]-(sum[i]-sum[k-1]))>m&&k<i)
        k++;
        //cout<<(i-k+1)<<' '<<a[i]<<' '<<(sum[i]-sum[k-1])<<' '<<k<<endl;
        ans=max(ans,i-k+1); 
    }
    cout<<ans;
    return 0;
}
/*
rp++ ro++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++ rp++
*/
/*
鎴戝眳鐒朵細 T1?
*/
