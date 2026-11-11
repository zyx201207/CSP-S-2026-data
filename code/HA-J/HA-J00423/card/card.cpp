#include <bits/stdc++.h>
using namespace std;
int n,m;int a[500005];
set<int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n>>m;
	int c1 = 0,c2 = 0;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
		if(a[i] == 1) c1++;
		if(a[i] == 2) c2++;
	}
	cout << c1<<" "<<c2;
	return 0;
}
