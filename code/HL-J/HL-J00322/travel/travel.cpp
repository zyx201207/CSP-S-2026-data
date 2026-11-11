#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("teavel.in","r",stdin);
	freopen("teavel.out","w",stdout);
	int a,d;
	string s,f;
	cin>>a>>s>>d>>f;
	if(a==d&&s==f)
	{
		cout<<"1111";
	}
	else if(a==d&&s!=f)
	{
			cout<<"1100";
	}
	else if(a!=d&&s==f)
	{
		cout<<"0011";
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
