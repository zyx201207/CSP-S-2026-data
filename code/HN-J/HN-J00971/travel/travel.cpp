#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<"1";
	else
		cout<<"0";
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2))
		cout<<1;
	else
		cout<<"0";
	string aa=s1.substr(2,1),ba=s2.substr(2,1);
	char a=aa[0],b=ba[0];
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2))
	{
		int A=max(int(a),int(b)),B=min(int(a),int(b));
		if(A!=int('D')&&B!=int('C'))
		{
			cout<<1;
			if(A-B==1)
				cout<<1;
			else
				cout<<"0";
		}
		else
			cout<<"00";
	}
	else
		cout<<"00";
	return 0;
}
