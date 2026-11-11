#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn],pre[maxn];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
		pre[i]=a[i]-a[i-1];
	}
	int r=0,now=0,ans=1,cos=0;
	for(int i=1;i<=n;i++)
	{
		while(r<=n&&now+pre[r]*(r-i+1)<=m)
		{
			now+=pre[r]*(r-i+1);
			cos+=pre[r];
			r++;
		}
		ans=max(ans,r-i+1);
		now-=cos;
		cos-=pre[i];
	}
	cout<<ans;
    return 0;
}
