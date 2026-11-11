#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005];
int gj[500005];
void game(int x)
{
	int tail=1;
	memset(gj,0,sizeof(gj));
	for(int i=x;i<=n;i++)
	{
		for(int j=1;j<=tail;j++)
		{
			if(gj[j]==a[i])
			{
				tail=j;
				break;
			}
		}
		tail++;
	}
	for(int i=1;i<=tail-1;i++)
	{
		ans[gj[i]]++;
	}
	return ;
}
int main()
{
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		game(i);
	}
	for(int i=1;i<=m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
