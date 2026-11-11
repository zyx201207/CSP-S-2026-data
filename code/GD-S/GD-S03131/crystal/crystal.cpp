#include<bits/stdc++.h>
using namespace std;
int a[500005],b[5005][5005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i][i]=1;
	}
	sort(a+1,a+1+n);
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int x=b[i-1][j]+a[i]+m;
			int y=b[i][j-1]+a[j]+m;
			if(x%(j-i+1)==0&&x/(j-i+1)>=a[j])
			{
				b[i][j]=b[i-1][j]+a[i];
				ma=max(ma,j-i+1);
			}
			else if(y%(j-i+1)==0&&y/(j-i+1)>=a[j])
			{
				b[i][j]=b[i][j-1]+a[j];
				ma=max(ma,j-i+1);
			}
		}
	}
	cout<<ma<<endl;
	return 0;
}
