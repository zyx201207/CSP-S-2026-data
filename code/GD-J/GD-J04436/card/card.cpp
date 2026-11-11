#include <bits/stdc++.h>
using namespace std;
vector<int> e;
long long n,m,a[500005],b[300005],c[300005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	} 
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			if (b[a[j]]==1)
			{
			    for (int k=n;k>=1;k--)
			    {
			    	if (e[k]==a[j])
			    	{
			    		e.erase(e.begin()+k);
			    		b[e[k]]--;
			    		break;
					}
					else
					{
						e.erase(e.begin()+k);
						b[e[k]]--;
					}
				}
			} 
			else
			{
				b[a[j]]=1;
			}
			e.push_back(a[j]);
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}
