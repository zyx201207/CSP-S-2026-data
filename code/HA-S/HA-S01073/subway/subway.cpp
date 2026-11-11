#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int k[310];
int a[310];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	int t;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			
			cin>>a[j]>>t;
			// 1 ting || 2 tai || 3 zhan
		}
	}
	while(q--)
	{
		int st1,en;
		cin>>st1>>en;
		cout<<(st1-en)*t*2+w[st1]+w[en]<<endl;
	}
	return 0;
}   