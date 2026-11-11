#include <bits/stdc++.h>
using namespace std;
int c;
int t;
int a[2000010];
int n,d;
int cha[2000010];
int p;
int ans=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];		
		}
		cha[1]=a[1];
		for(int i=2;i<=n;i++)
		{
			cha[i]=a[i]-a[i-1];
		}
		int flag=1;
		for(int i=1;i<n;i++)
		{
			if(cha[i]==cha[i+1])
			{
				flag=0;
			}
			else
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<114514<<endl;
		}
	}
	return 0;
}
