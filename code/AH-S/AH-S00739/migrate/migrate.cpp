#include<bits/stdc++.h>
using namespace std;
long long int dis[1000][1000],a[1000010],mi[100100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(int p=0;p<t;p++)
	{
		int n,d,js=0;
		cin>>n>>d;
		memset(a,0,sizeof(a));
		memset(mi,1000,sizeof(mi));
		mi[2]=1;
		dis[1][1]=0;
		dis[1][2]=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int j=3;j<=n;j++)
		{
			for(int i=1;i<j;i++)
			{
				if(a[j]-a[i]<=d)
				{
					dis[i][j]+=dis[i-1][j];
					mi[j]=min(mi[j],mi[i-1]+1);
				}
				for(int k=i+1;k<j;k++)
				{
					if(mi[j]>mi[k]+1){
						dis[i][j]+=dis[i][k];
						mi[j]=mi[k]+1;
					}
				}
			}
		}
		for(int j=2;j<=n;j++)
		{
			for(int i=1;i<j;i++)
			{
				if(dis[i][j]==2)
				{
					js++;
				}
			}
		}
		cout<<js<<endl;
		
	}
	return 0;
}
