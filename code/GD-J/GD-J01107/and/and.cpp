#include<bits/stdc++.h>
using namespace std;
int n,m,an,s,a[200005],u[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=29;i>=0;i--)
	{
		s=0;
		for(int j=1;j<=n;j++)
		{
			if(u[j])continue;
			if(a[j]>>i&1)s++;
		}
		if(s>=m)
		{
			an+=1<<i;
			for(int j=1;j<=n;j++)if(a[j]>>i&1^1)u[j]=1;
		}
	}
	cout<<an;
	return 0;
}
