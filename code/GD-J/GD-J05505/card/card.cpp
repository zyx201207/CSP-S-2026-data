#include<bits/stdc++.h>
using namespace std;
int n,tar;
vector<int> zhuomian;
bool dengji[(int)3e5+1000];
int a[(int)5e5+1000];
int ans[(int)5e5+1000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>n>>tar;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(dengji[a[j]])
			{
				while(zhuomian.back()!=a[j])
				{
					 
					zhuomian.pop_back();
				}
				
			}
			else
			{
				dengji[a[j]]=true;
				zhuomian.push_back(a[j]);
			}
			
		}
		for(int i=0;i<zhuomian.size();i++)
		{
			
			if(zhuomian[i]<=tar)
			{
				ans[zhuomian[i]]++;
			}
		}
		memset(dengji,0,sizeof dengji);
		zhuomian.clear();
	}
	for(int i=1;i<=tar;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
