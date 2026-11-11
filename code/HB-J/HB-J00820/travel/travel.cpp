#include <bits/stdc++.h>
using namespace std;
string a_1,a_2,b_1,b_2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a_1>>a_2>>b_1>>b_2;
	if(a_1!=b_1)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(a_2[0]==b_2[0] && a_2[1]==b_2[1])
	{
		cout<<1;
		char i=a_2[2],j=b_2[2];
		int x=abs(i-j);
		if((i-'A'<=2 && j-'A'>=3) || (j-'A'<=2 && i-'A'>=3))
		{
			cout<<"00";
			return 0;
		}
		cout<<1;
		if(x==1)
		{
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	cout<<"000";
	return 0;
}
