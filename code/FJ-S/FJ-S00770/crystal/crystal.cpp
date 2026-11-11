#include<bits/stdc++.h>
using namespace std;
long long int a[500000+10];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	long long int n,m;
	int cs=0,s=1;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			for(int z=i; z>=1; z--)
			{
				cs=cs+a[j]-a[z];
			}
			if(cs<=m)
			{
				a[i]=a[j];
				s++;
			}
		}
	}
	cout<<s;

	return 0;
}
