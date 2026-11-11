#include<bits/stdc++.h>
#include<queue>
using namespace std;
int a[50005];//ÅÆ 
int b[30005];//Êý×Ö 
bool c[30005];//ÅÐ 
int d[50005];//¶ÓÁÐ 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int t = n;
	int cnt = 1 , cnt1 = 1;
	for(int o = 1; o <= n;o++)
	{
		for(int i = cnt;i<= n;i++)
		{
			if(c[a[i]] == 0)
			{
				c[a[i]]=1;
				d[cnt1] = a[i];
				cnt1++;
			}
			else
			{
				bool p = 0;
				for(int j = 1; j <= cnt1;j++)
				{	
					if(d[j] == a[i]&&p == 0)
					{
						for(int k = j; k <= cnt1;k++)
						{
							c[d[k]] = 0;
							d[k] = 0;
						}
						cnt1 = j+1;
						d[cnt1] = a[i];
						p = 1;
					}
				}
			}
		}
		for(int i = 1; i < cnt1;i++)
		{
			b[d[i]]++;
		}
		for(int i = 1; i <= m;i++)
		{
			c[i] = 0;	
		}
		cnt1 = 0;
		cnt++;
		t--;
	}
	for(int i = 1; i <= m;i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}
