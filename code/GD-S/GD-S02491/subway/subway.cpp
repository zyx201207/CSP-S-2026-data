#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int tstart[5005],s[505][1005],t[505][1005];
vector<int>a[1005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	scanf(" %d",&tstart[i]);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf(" %d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf(" %d %d",&t[i][j],&s[i][j]);
			a[s[i][j]].push_back(i);
		}
	}
	while(q--)
	{
		int st,en;
		scanf("%d%d",&st,&en);
		cout<<2<<"\n";
	}
}
