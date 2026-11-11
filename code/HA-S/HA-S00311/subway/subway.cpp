#include<bits/stdc++.h>
#include<vector>
using namespace std;
int a[1005][1005],b[1005][1005],c[1005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	for(int i=1;i<=n;++i)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;++j)
		{
			cin>>a[i][j]>>b[i][j];
		}
	}
	for(int i=1;i<=q;++i) 
	{
		int qq;
		cin>>qq;
	}
}
