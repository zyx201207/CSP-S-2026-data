#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	if(m == 1)
	{
		cout << n;
	}
}
