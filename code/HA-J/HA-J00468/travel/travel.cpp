#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string n, m,v = "0000";
	cin >> a >> n >> b >> m;
	if(a == b)
	{
		v[0] = '1';
		if(n[0] == m[0] && n[1] == m[1])
		{
			v[1] = '1';
			if(n[2] <= 'C' && m[2] <= 'C' || n[2] >= 'D' && m[2] >= 'D')
			{
				v[2] = '1';
				if(n[2]+1 == m[2] || m[2]+1 == n[2])
				{
					v[3] = '1';
				}
			}
		}
	}
	cout << v;
	return 0;
}
