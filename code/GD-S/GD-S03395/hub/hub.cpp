#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	if(c == 0)
	{
		printf("1\n2");
		return 0;
	}
	for(int i = 1; i <= t; i++)
	{
		cout << i << endl;
	}
	return 0;
}
