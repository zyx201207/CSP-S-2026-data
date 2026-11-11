#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
int a[200005];
bool flag[200005];
int n;
int m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int ans=-1;int id=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>ans)
		{
			ans=a[i];
			id=i;
		}
	}
	flag[id]=true;
	for(int i=2;i<=m;i++)
	{
		int t=0;id=0;
		for(int j=1;j<=n;j++)
		{
			if(flag[j]==0&&a[j]>t)
			{
				t=a[j];
				id=j;
			}
		}
		flag[id]=1;
		ans=(ans&t);
	}
	cout<<ans<<endl;
	return 0;
}
