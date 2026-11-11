//GZ-S00231 贵阳市第三中学 杨鑫豪 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,zt[500];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=m;i++)
	{
		cin>>zt[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x;
			cin>>x;
			cin>>a[x];
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<zt[x]+zt[y]+a[x]+a[y]<<endl;
	}
	return 0;
}
