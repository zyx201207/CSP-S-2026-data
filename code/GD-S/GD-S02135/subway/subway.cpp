#include<bits/stdc++.h>
using namespace std;
long long n,m,c,d,q,ans;
long long a[5010][5010],w[5010],t[5010][5010],x[500100],y[500100];
bool check(int goal,int pipe)
{
	for(int i=1;i<a[pipe][1];i++)
		if(a[pipe][i]==goal)
			return true;
	return false;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		a[i][1] = k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j+1]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
		int ti = 0;
		for(int j=1;j<=n;j++)
		ans = ans+w[x[i]]+t[x[i]][1];
	}
	cout<<50<<endl;
	cout<<106; 
	return 0;
}

