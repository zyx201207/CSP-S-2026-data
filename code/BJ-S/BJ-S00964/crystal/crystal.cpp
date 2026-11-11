#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum[500001],a[5000001],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int l=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]*(i-l+1)-(sum[i]-sum[l-1])<=m)
        {
            ans=max(ans,i-l+1);
        }
        else
        {
            while(l<=i&&a[i]*(i-l+1)-(sum[i]-sum[l-1])>m)
            {
                l++;
            }
            ans=max(ans,i-l+1);
        }
    }
    cout<<ans;
	return 0;
}
