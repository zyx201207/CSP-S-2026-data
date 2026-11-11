#include <bits/stdc++.h>
using namespace std;
long long n,m,x[300010],ans[500010];
bool d[500010];
stack<long long> a;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> ans[i];
	int tep = 1;
	for(int i=1;i<=n;i++)
	{
		for(int j=tep;j<=n;j++)
		{
			if(d[ans[j]]==1)
			{
				while(a.top()!=ans[j])
					a.pop();
				a.pop();
			}
			a.push(ans[j]);
			d[ans[j]] = 1;
		}
		for(int j=tep;j<a.size();j++)
		{
			int teb = a.top();
			x[teb]++;
		}
		tep++;
	}
	for(int i=1;i<=m;i++)
		cout << x[i] << ' ';
	cout << endl;
	return 0;
 } 
