#include<iostream>
#include<algorithm>
using namespace std;
long long cds[500005],nbs[500005]={0},n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>cds[i];
	}
	for(int t=1;t<=n;t++)
	{
		int biao[m+1]={0},end=t;
		for(int i=t;i<=n;i++)
		{
			if(biao[cds[i]]==0)
			{
				biao[cds[i]]=1;
			}
			else
			{
				end=i;
			}
		}
		for(int i=end;i<=n;i++)
		{
			nbs[cds[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<nbs[i]<<" ";
	}
	return 0;
}
/*
10 3 
3 1 2 1 3 2 3 1 2 1
4 3
1 2 1 3
*/
