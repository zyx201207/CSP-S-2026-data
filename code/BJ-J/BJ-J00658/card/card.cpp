#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],id[500005];

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		id[a[i]] = (id[a[i]] == 0 ? i : id[a[i]]);
	}
	
	for(int i = 1;i <= m;i++)
		cout << m - id[i] + 1 << ' ';
	return 0;
}
 
