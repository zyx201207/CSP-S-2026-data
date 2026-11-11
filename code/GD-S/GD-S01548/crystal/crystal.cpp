#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.end(),cmp);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int z=m,tot=1;
		for(int j=i+1;j<n;j++)
		{
			if(a[i]-a[j]>z)
				break;
			z-=a[i]-a[j];
			tot++;
		}
		ans=max(ans,tot);
	}
	cout<<ans<<'\n';
	return 0;
}
