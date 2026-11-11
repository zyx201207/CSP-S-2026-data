#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r",stdin);
	freopen("string.out","w",stdout);
	string a,b;
	getline(cin, a);
	b=reverse(a.begin(), a.end());
	if(b==a)
	{
		cout<<"0";
	}
	return 0;
}
