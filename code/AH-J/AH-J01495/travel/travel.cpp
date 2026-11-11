#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,s1,s3;
char s2,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	s1=b.substr(0,2);
	s2=b[2];
	s3=d.substr(0,2);
	s4=d[2];
	if(a==c)
	{
		cout<<1;
		if(s1==s3)
		{
			cout<<1;
			if((s2<='C' && s4<='C') || (s2>'C' && s4>'C'))
			{
				cout<<1;
				if(s2+1==s4 || s4+1==s2)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
				cout<<"00";
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
