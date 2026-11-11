#include<bits/stdc++.h>
using namespace std;
int a[200010];
int aww(int x,int y)
{
	return x|y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int i,j,s=0,max1=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		s=0;
		for(j=i;j<=m;j++)
		{
			s=s+aww(a[i],a[j]);
			cout<<a[i]<<" "<<a[j]<<" "<<s<<endl;
		}
		if(max1<s) max1=s;
	}
	cout<<max1<<endl;
	return 0;
}
