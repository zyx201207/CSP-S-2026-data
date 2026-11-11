#include<bits/stdc++.h>
using namespace std;
struct aaa
{
	long long dz,zx;
}a[1000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].dz;
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		aaa o[1000005];
		for(int j=1;j<=x;j++)
		{
			 cin>>o[j].z>>o[j].t;
		}
		for(int j=2;j<=x;j++)
		{
			b[o[j-1].z][o[j].z].t=0;
			b[o[j-1].z][o[j].z].x=x;
			b[o[j].z][o[j-1].z].t=0;
			b[o[j].z][o[j-1].z].x=x;
		}
	}
	return 0;
}
