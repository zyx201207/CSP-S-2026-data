#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m;
ll a[N],b[N],c[N],com,ans[N];
bool f;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>ss>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		//初始化
		for(int j=1;j<=n;j++) 
		{
			b[i]=a[i];
			c[i]=0;
			com=0;
		} 
		//每一回合 
		for(int j=i;j<=n;j++)
		{
			//查找
			f=0;
			for(int k=1;k<=com;k++)
			{
				if(c[k]==b[j]) 
				{
					f=1;
				}
			} 
			//找到清空 
			if(f==1)
			{
				com=0;
			}
			c[++com]=b[j];	
			//否则加入 
		}
		//回合结算
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=com;k++)
			{
				if(c[k]==j) ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}


