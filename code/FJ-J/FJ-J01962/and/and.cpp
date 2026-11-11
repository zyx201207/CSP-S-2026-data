#include <bits/stdc++.h>
using namespace std;
unsigned long long m,n,num,ans=0,x=0;
vector<long long> a;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> num;
		a.push_back(num);
	}
	int tep;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>ans)
		{
			ans = a[i];
			tep = i;
		}
	}
	a[tep] = 0;
	m--;
	while(m!=0)
	{
		x = 0;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]>x)
			{
				x = a[i];
				tep = i;
			}
		}
		a[tep] = 0;
		ans = ans & x;
		m--;
	}
	cout << ans << endl;
	return 0;
} 
