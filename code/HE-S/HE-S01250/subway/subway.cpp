#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
struct W
{
	int lo;
	int a[500005];
	int t[500005];
};
int rs[505][50005];
int rt[505][50005];
struct Q
{
	int u;
	int v;
};
Q s[10005];
int l[5000][5000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	bool sw=1;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<=5000;i++)
	{
		for(int j=0;j<5000;j++)
		{
			l[i][j]=100000000;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>rs[i][0];
		rt[i][0]=rs[i][0];
		for(int j=1;j<=rt[i][0];i++)
		{
			cin>>rs[i][j]>>rt[i][j];
   	   	}
   	   	for(int j=1;j<rs[i][0];j++)
   	   	{
   	   		for(int k=i+1;k<=rs[i][0];k++)
			{
				int tmp=rt[i][j]+rt[i][k];
				l[rs[i][j]][rs[i][k]]==min(l[rs[i][j]][rs[i][k]],tmp);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int tmp1,tmp2;
		cin>>tmp1>>tmp2;
		int ans=0;
		cout<<w[tmp1]+w[tmp2]+l[tmp1][tmp2]<<endl;
	}
	return 0;
}
