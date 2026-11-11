#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","d",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>c2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(c1==c2||s1==s2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
