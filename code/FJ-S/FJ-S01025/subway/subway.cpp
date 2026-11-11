#include<bits/stdc++.h>
using namespace std;
long long w[505],k[505],a[505][505],t[505][505],x[100005],y[100005],tot[505];
bool s[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,f1,f2;
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;++i)
	{
		cin>>w[i];
	}
	for (int i=1;i<=n;++i)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];++j)
		{
			cin>>a[i][j]>>t[i][j];
			s[a[i][j]][i]=1;
			tot[a[i][j]]++;
		}
	}
	for (int i=1;i<=q;++i)
	{
		cin>>x[i]>>y[i];
		for (int j=1;j<=n;++j)
		{
			if (s[x[i]][j]==1&&s[y[i]][j]==1)
			{
				for (int g=1;g<=k[j];++g)
				{
					if (a[j][g]==x[i])
					{
						f1=g;
					}
					if (a[j][g]==y[i])
					{
						f2=g;
					}
				}
				cout<<w[x[i]]+t[j][f1]+t[j][f2]+w[y[i]]<<endl;
				break;
			}
		}
	}
	return 0;
}
