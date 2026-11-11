#include<bits/stdc++.h>
//#define LL long long
using namespace std;
int n,m,ta;
int a[500005],z[500005];
struct node
{
	int t,id;
}us[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ta=i;
		for(int i=1;i<=n;i++)
			us[i].t=0,us[i].id=0;
		for(int j=i;j<=n;j++)
		{
			if(us[a[j]].t==1) 
			{
				ta=us[a[j]].id;
			}
			else 
			{
				ta++;
				us[a[j]].t=0;
				us[a[i]].id=i;
			}
		}
		for(int j=1;j<=m;j++)
			if(us[j].t) z[j]++;
	}
	for(int i=1;i<=m;i++) cout<<z[i]<<' ';
	return 0;
}

