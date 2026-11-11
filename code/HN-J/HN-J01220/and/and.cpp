#include <bits/stdc++.h>
using namespace std;
int n,m,p,maxx=0;
vector<int>a;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	a.resize(n+1);	
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> p;
		a.push_back(p);
	}
	for(int i = 1;i<=a.size()-m+1;i++)
	{
		int num=a[i];
		for(int j = i+1;j<=i+m-1;j++)
		{
			num=num&a[j];
		}
		maxx=max(num,maxx);
	}
	cout << maxx;
	return 0;
}
