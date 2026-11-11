#include<bits/stdc++.h>
using namespace std;
int zhipai[5005],n,m,a[5005]; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<rand()%(n-1)+1<<" ";
	}
	return 0;
}
