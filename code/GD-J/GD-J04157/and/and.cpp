#include<iostream>
#define int long long
using namespace std;
int n,m,ans; 
int b[200012],f[200012][42],flag[200012];
void chai(int x,int num)
{
	for(int i=0;i<=30;i++)
	{
		int u=30-i;
		if(num&(1<<u))f[x][i]=1;
		else f[x][i]=0;
	}
}
int suan(int x)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(flag[i])continue;
		if(f[i][x]==1)sum++;
	}
	return sum;
}
void gai(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(f[i][x]==0)flag[i]=1;
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)chai(i,b[i]);
	for(int i=0;i<=30;i++)
	{
		if(suan(i)>=m)
		{
			gai(i);
			ans+=1<<(30-i); 
		}
	}
	cout<<ans;
} 
/*
5 3
31 3 1 15 7
*/
