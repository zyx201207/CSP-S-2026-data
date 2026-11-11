#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int c[10005][10005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}int ma=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c[i][j]=(j-i)*b[j]+c[i][j-1];
			if(c[i][j]==m) ma=max(ma,j-i+1);
		} 
	}
	cout<<ma;
	return 0;
}
