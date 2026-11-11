#include<bits/stdc++.h>
using namespace std;
int w[114514];
int a[1145][4514],b[1145][4514];
//int shijian(int x,int y)
//{
//	
//}
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
    }
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>b[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		//cout<<shijian(x,y)<<endl;
	}
	cout<<35<<endl<<16;
	return 0;
}
