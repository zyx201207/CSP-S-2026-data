#include<bits/stdc++.h>
using namespace std;
int a[200005],f[3];
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		bool one=0,tow=0;
		for(int j=1+i;j<=n;j++)
		{
			if(a[j]==1) one=1;
			if(a[j]==2) tow=1;
		}
		if(one) f[1]++;
		if(tow) f[2]++;
		
	}
	cout<<f[1]<<" "<<f[2];
	return 0;
}
