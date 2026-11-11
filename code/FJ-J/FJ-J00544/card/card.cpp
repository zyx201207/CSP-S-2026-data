#include <bits/stdc++.h>
using namespace std;
int summ[3005];
int a[5005];
vector<int> q;
vector<int> huan;
int n, m;
int main ()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	//int l = 0, r = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			if(q.empty())
			{
				q.push_back(a[j]);
				continue;
			}
			bool flag = true;
			for(auto am:q)
			{
				if(am == a[j]) flag = false;
			}
			if(flag == 1)
			{
				q.push_back(a[j]);
				continue;
			}
			else
			{
				for(int i1 = 0;i1 < (int)q.size();i1++)
				{
					if(q[i1] == a[j]) {
						for(int j1 = 0;j1 <= i1;j1++)
						{
							huan.push_back(q[j1]);
						}
						q.clear();
						for(int j1 = 0;j1 <= i1;j1++)
						{
							q.push_back(huan[j1]);
						}
						huan.clear();
						break;
					}		
				}
				
			}
			/*for(auto x:q)
		    {
			summ[x]++;
		    }*/
		}
		for(auto x:q)
		{
			summ[x]++;
		}
	}
	for(int i = 1;i <= m;i++)cout << summ[i]<<" ";
	return 0;
}
