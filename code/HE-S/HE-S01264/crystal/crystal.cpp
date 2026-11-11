#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[500010],sum[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int i,j,k;
    cin>>n>>m;
    for(i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    sum[1]=a[1];
    for(i=2; i<=n; i++) sum[i]=sum[i-1]+a[i];
//    for(i=1; i<=n; i++) cout<<sum[i]<<' ';
    i=1; j=1; k=1;
    while(i<=n)
    {
        if(a[i]*k-(sum[i]-sum[j-1])<=m)
        {
            i++; k++;
        }else
        {
            i++; j++;
        }
    }
    cout<<k-1;
    return 0;
}
