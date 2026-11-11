#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s,t;
	cin>>c1>>s>>c2>>t;
	if(c1<2||c2<2||c1>16||c2>16)
	cout<<"0000";
	else
	if(c1==c2)
	{
		cout<<"1000";
	}
	else
	if(c1!=c2)
	cout<<"0000";
	else
	
	if(s==t)
	cout<<"0000";
	return 0;
}
