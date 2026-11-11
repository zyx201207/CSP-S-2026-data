#include <bits/stdc++.h>
using namespace std;
string s,str,s1,str1;
int main()
{
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>s>>str>>s1>>str1;
if(s==s1)
{
	cout<<"1";
	int t=int(str[0]-'0')*10+int(str[1]-'0'),t1=int(str1[0]-'0')*10+int(str1[1]-'0');
	if(t==t1)
	{
		cout<<"1";
		if((str[2]<='C'&&str1[2]<='C') || (str[2]>'C'&&str1[2]>'C'))
		{
			cout<<"1";
			char c=str[2],c1=str1[2];
			if(c==char(c1+1)||c1==char(c+1))cout<<"1";
			else cout<<"0";
		}
		else cout<<"00";
	}
	else cout<<"000";
}
else cout<<"0000";
return 0;
}
