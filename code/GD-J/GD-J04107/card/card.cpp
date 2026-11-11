#include<iostream>
using namespace std;
#define ll unsigned long long 
const int M=50005;
int n, m;
int cnt[M][M]; //cnt[i][j]: 第i-n张牌中点数为i的牌出现次数 
int pos[M][M]; //pos[i][j]: 第i-n张牌中点数为i的牌的最后出现位置
int a[M];
int r[M];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out","w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		cnt[i][a[i]]++;
		if (cnt[i][a[i]]==1) pos[i][a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int p=i;
		for (int j=1;j<=n;j++)
		{
			if(cnt[i][j]>1) p=max(p, pos[i][j]);
		}
		for(int j=p;j<=n;j++)
		{
			r[j]++;
		}
	}for(int i=1;i<= m;i++)
	{
		cout << r[i]<<' ';
	}
	return 0;
 } 
