#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
long long ans=0;
long long ansz=0;
long long id=1;
long long idz=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			ans+=a[i]-a[j];
			if(ans<=m)
			{
				ansz=ans;
				id++;	
			}
		if(j==1)ans=0;
		}
		idz=max(id,idz);
		ans=0;
		id=1;
	}
 	cout<<idz;
}
