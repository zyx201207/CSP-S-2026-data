#include<bits/stdc++.h>
using namespace std;
int n,m,m2,a[500005],ans,sum;
bool cmp(int fi,int se)
{
	return fi>se;
}
int main()
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
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		sum=1;
		m2=m;
		for(int j=i+1;j<=n;j++)
		{
			if(m2<(a[i]-a[j]))break;
			sum++;
			m2-=(a[i]-a[j]);
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
