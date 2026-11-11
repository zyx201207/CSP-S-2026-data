#include<iostream>
#include<queue>
using namespace std;
long long s[300005],a[500005];
bool sf[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	queue <long long>aa;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int j = 1;j <= n;j++)
	{
		for(int k = 1;k <= m;k++)
		{
			sf[k] = 0;
		}
		for(int i = j;i <= n;i++)
		{
			
			if(!sf[a[i]])
			{
				sf[a[i]] = 1;
				aa.push(a[i]);
			}
			else
			{
				aa.push(a[i]);
				while(aa.front() != a[i])
				{
					long long lsh = aa.front();
					aa.pop();
					aa.push(lsh);
				}
				aa.pop();
				while(aa.front() != a[i])
				{
					aa.pop();
				}
				aa.pop();
				aa.push(a[i]);
			}
		}
		while(!aa.empty())
		{
			s[aa.front()]++;
			aa.pop();
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << s[i] << " ";
	}
	return 0;
	
 } 
