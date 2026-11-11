#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[200015],f=0,s=0,c=0;
int main()
{

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
	{
		s=0;
		int h=m;
		for(int q=1;q<=i;q++)
		{
			if(h-(a[i]-a[q])<0)
			continue;
			s++ ;h-=(a[i]-a[q]);
		}
		f=max(s,f);
	}
	cout<<f;
	return 0;
 } 
