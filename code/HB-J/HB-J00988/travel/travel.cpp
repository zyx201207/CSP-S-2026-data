#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int p1,p2;
	string num1,num2;
	cin>>p1>>num1>>p2>>num2;
	if(p1!=p2)
		cout<<"0000\n";
	else
	{
		cout<<1;
		if(num1[0]==num2[0]&&num1[1]==num2[1])
			cout<<1;
		else
			cout<<"000\n";
		if((num1[2]<='C'&&num2[2]<='C')||(num1[2]>'C'&&num2[2]>'C'))
		{
			cout<<1;
			if(abs(num1[2]-num2[2])==1)
				cout<<"1\n";
			else
				cout<<"0\n";
		}
		else
			cout<<"00\n";
	}
	return 0;
}
