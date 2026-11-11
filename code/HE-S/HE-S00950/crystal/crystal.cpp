#include<iostream>
#include<algorithm>
int n,m,ans=0;
int a[500005];
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=i+1;j<=m;j++)
		{
			if(i==a[i]) ans++;
		}
	}
	cout<<ans;
}
