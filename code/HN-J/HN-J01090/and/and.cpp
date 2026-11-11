#include<bits/stdc++.h>
using namespace std;
long long a,c[200005];
int n,m,dl[200005],num;
bool b[200005][35];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		dl[i]=1;
		cin>>a;
		c[i]=a;
		int f=0;
		while(a!=0)
		{
			b[i][f]=a%2;
			a/=2;
			f++;
		}
	}
	for(int i=32;i>=0;i--)
	{
		if(m==0)
			break;
		for(int j=1;j<=n;j++)
			if(b[j][i]==1&&dl[j]==1)
				num++;
		if(m>=num&&num>=2)
			for(int j=1;j<=n;j++)
			{
				if((b[j][i]==1||(i==0&&m!=0))&&dl[j]==1)
				{
					dl[j]=2;
					m--;
				}
			}
		if(num>m)
			for(int j=1;j<=n;j++)
			{
				if(b[j][i]==0&&dl[j]==1)
					dl[j]=0;
			}
		num=0;
	}
	long long ans=1073741824-1;
	for(int i=1;i<=n;i++)
		if(dl[i]==2)
			ans=(ans&c[i]);
	cout<<ans;
	return 0;
}
