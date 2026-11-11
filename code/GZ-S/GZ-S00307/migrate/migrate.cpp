//GZ-S00307 遵义航天高级中学  胡雯雯

#include <bits/stdc++.h>
using namespace std;
const int MAX=200005;
queue<int> que;
long long int c,t,n,d;
int a[30][MAX],b[30][MAX];
int cont,sum,ttt;
int shuangjin(int x)
{
	for(int i=2;i<=d;i++)
	{
		for(int j=1;j<i;j++)
		{
			for(int z=1;z<=sum;z++)
			{
				if(b[x][z]%(i+j)==0)
					cont++;
			}
		}         
	}
	que.push(cont);
}


int main()
{
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=d;j++)
			cin>>a[i][j];
		for(int j=1;j<=d;j++)
		{
			b[i][j]=a[i][j+1]-a[i][j];
			sum++;
			if(b[i][j]>d)
				break;
		}
		for(int j=1;i<=sum;j++)
		{
			b[i][j]=b[i][j-1]+b[i][j];
		}
		shuangjin(i);
	}
	for(int i=1;i<=t;i++)
	{
		cout<<que.back();
		que.pop();
	}
	return 0;
}


