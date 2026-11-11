#include<bits/stdc++.h>
using namespace std;
int a[200010][33],ans;
bool dx[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		int j=1;
		while(x)
		{
			if(x%2) a[i][j]=1;
			x/=2;
			j++;
		}
	}
	for(int i=31;i>=1;i--)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
			if(a[j][i]==1&&dx[j]==0) sum++;
		if(sum>=m)
		{
			for(int j=1;j<=n;j++)
				if(a[j][i]==0) dx[j]=1;
			ans+=pow(2,i-1);
		}
	}
	cout<<ans;
	return 0;
}
