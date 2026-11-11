#include<bits/stdc++.h>
using namespace std;
string aa,af,ba,bf;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>aa>>af>>ba>>bf;
	if(aa!=ba)
	{
		cout<<"0000";
		return 0;
	}
	if((af[0]!=bf[0])||(af[1]!=bf[1]))
	{
		cout<<"1000";
		return 0;
	}
	cout<<"1111";
	return 0;	
} 
