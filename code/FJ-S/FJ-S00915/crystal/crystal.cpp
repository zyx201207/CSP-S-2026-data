#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=(int)(5e5+10);//请检查数组大小
int a[MAXN];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//请开freopen
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int r=1,ans=0,maxn=0;
	a[n+1]=LLONG_MAX;
	for(int l=1;l<=n;l++)
	{
		while(ans<=m and r<=n)
		{
			//cout<<l<<" "<<r<<" "<<ans<<endl;
			maxn=max(maxn,r-l+1);
			r++;
			ans+=(r-l)*(a[r]-a[r-1]);
		}
		//cout<<l<<" "<<r-1<<endl;
		ans-=a[r]-a[l];
	}
	cout<<maxn;
	return 0;
}



