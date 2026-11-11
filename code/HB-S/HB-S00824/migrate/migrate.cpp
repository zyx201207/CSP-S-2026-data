#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,mi,mif;
long long a[2000005],cnt;
vector<long long>b[2000005];
void find(int x,int y,int step)
{
	if(x>y)return;
	if(x==y){
		if(step<mi){mi=step;mif=1;}
		else if(step==mi)mif++;
		return;
	}
	for(int i=0;i<b[x].size();i++)
	{
		find(b[x][i],y,step+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		for(int i=1;i<=n;i++)b[i].erase(b[i].begin(),b[i].end());
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;a[j]<=a[i]+d&&j<=n;j++)
			{
				b[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				mi=0x3f3f3f3f,mif=0;
				find(i,j,0);
				if(mif==2)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
