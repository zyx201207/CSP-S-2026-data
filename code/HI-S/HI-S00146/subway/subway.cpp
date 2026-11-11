#include<bits/stdc++.h>
using namespace std;
int road[2005][2005];
int a[1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	memset(road,0x3f,sizeof(road));
	cin>>c>>n>>m>>d>>q;
	int ff1,ff2;
	for(int i=1;i<=m;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		for(int j=1;j<=c;j++)
		{
			cin>>ff1>>ff2;
			road[ff1][m+i]=ff2;
			road[m+i][ff1]=ff2;
		}
	}
	for(int i=1;i<=m+n;i++)
	road[i][i]=0;
	for(int k=1;k<=m+n;k++)
	{
		for(int i=1;i<=m+n;i++)
		{
			for(int j=1;j<=m+n;j++)
			{
				if(road[i][k]+road[k][j]<road[i][j])
				road[i][j]=road[i][k]+road[k][j];
			}
		}
	}
	int startt,endd;
	while(q--)
	{
		cin>>startt>>endd;
		cout<<road[startt][endd]+a[startt]+a[endd]<<endl;
	}
 	return 0;
}

