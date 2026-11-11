#include<bits/stdc++.h>
using namespace std;
int n,d,a[2000005];
int fly(int sta,int end,int ste)
{
	if(sta==end)
	{
		return ste;
	}
	else
	{
		long long minn=1e18;
		long long num=0;
		for(int i=sta;i<=end;i++)
		{
			if(a[i]-a[sta]>d)
			{
				break;
			}
			else
			{
				fly(i,end,ste+1);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int num=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(fly(i,j,0)==2)
				{
					num++;
				}
			}
		}
		cout<<num<<"\n";
	}
	return 0;
}
