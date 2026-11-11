//GZ-J00312,韦胤帆,贵阳市第十八中学
#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],f[1001],s[100001],k[1000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		f[a[i]]=i;
	}
	for(int p=0;p<n;p++)
	{
		int t=0;
		for(int i=p;i<n;i++)
		{
			s[t]=a[i];
			t++;
			i=f[a[i]];
		}
		for(int i=0;i<t;i++)
		{
			k[s[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<k[i]<<" ";
	return 0;
}
