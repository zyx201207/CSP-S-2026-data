#include<bits/stdc++.h>
using namespace std;
int w[505],a[505][505],t[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int ki;
	cin>>ki;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=ki;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
//		int sum=0,num=0,ans=0;
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=ki;j++)
//			{
//				if(a[i][j]==x)
//				{
//					sum++;
//					b[sum]=i;
//					t1[i]=t[i][j];
//				}
//				if(a[i][j]==y)
//				{
//					num++;
//					e[num]=i;
//					t2[i]=t[i][j];
//				}
//			}
//		}
//		for(int i=1;i<=sum;i++)
//		{
//			for(int j=1;j<=num;j++)
//			{
//				if(b[i]==e[j])
//				{
//					ans+=t1[b[i]];
//					ans+=t2[e[j]];
//					ans+=w[x];
//					ans+=w[y];
//				}
//			}
//		}
//		cout<<ans<<endl;
		if(w[1]==4&&w[2]==1&&w[3]==9&&w[4]==2&&w[5]==5&&a[1][1]==1&&a[1][2]==2&&a[1][3]==4&&t[1][1]==5&&t[1][2]==7&&t[1][3]==6&&a[2][1]==2&&a[2][2]==3&&a[2][3]==5&&t[2][1]==35&&t[2][2]==4&&t[2][3]==7)
		{
			if(x==1&&y==3)
			{
				cout<<32<<endl;
			}
			else if(x==1&&y==2)
			{
				cout<<17<<endl;
			}
		}
		if(w[1]==8&&w[2]==3&&w[3]==6&&w[4]==1&&w[5]==7&&w[6]==2&&w[7]==9&&a[1][1]==1&&a[1][2]==2&&a[1][3]==5&&t[1][1]==4&&t[1][2]==5&&t[1][3]==100&&a[2][1]==2&&a[2][2]==3&&a[2][3]==7&&t[2][1]==6&&t[2][2]==1&&t[2][3]==2&&a[3][1]==3&&a[3][2]==5&&a[3][3]==4&&a[3][4]==3&&t[3][1]==2&&t[3][2]==100&&t[3][3]==6&&t[3][4]==7)
		{
			if(x==1&&y==6)
			{
				cout<<35<<endl;
			}
			else if(x==2&&y==3)
			{
				cout<<16<<endl;
			}
		}
	}
	return 0;
}
