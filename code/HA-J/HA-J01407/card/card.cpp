#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],lst[3010],ans[3010];
bool now[500001][3001];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(lst[a[i]]==0)
		{
			for(int j=1;j<=m;j++)
				now[i][j]=now[i+1][j],ans[j]+=now[i][j];
			now[i][a[i]]++;
			ans[a[i]]++;
			lst[a[i]]=i;
		}
		else
		{
			for(int j=1;j<=m;j++)
				now[i][j]=now[lst[a[i]]][j],/*cout<<now[i][j]<<' ',*/ans[j]+=now[i][j];
			//cout<<endl;
			lst[a[i]]=i;
		}
	}
	//cout<<clock()-be<<endl;
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	cout<<endl;
	
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

*/
