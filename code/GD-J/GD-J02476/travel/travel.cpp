#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	long long ch1,ch2,ha1,ha2;
	char n1=s1.back(),n2=s2.back();
	s1=s1.substr(0,s1.size()-1);
	s2=s2.substr(0,s2.size()-1);
	ch1=stoll(c1);
	ch2=stoll(c2);
	ha1=stoll(s1);
	ha2=stoll(s2);
	//cout<<ha1<<" "<<ha2<<endl; 
	if(ch1==ch2)
	{
		cout<<"1";
		if(ha1==ha2)
		{
			cout<<"1";
			if((n1<='C')&&(n2<='C'))
			{
				cout<<"1";
				if(abs((int)n2-(int)n1)==1) cout<<"1";
				else cout<<"0";
			}
			else if((n1>'C')&&(n2>'C'))
			{
				cout<<"1";
				if(abs((int)n2-(int)n1)==2) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
