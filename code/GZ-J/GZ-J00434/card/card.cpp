//GZ-J00434 雷信洋 贵阳市第三十四中学 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[200010],b[300010];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
		b[a[i]]++;
		if(i==n)
		{
			b[a[i]]=n;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(b[a[i]]%2==0&&b[a[i]]<n)
		{
			b[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
