#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	bool f1,f2,f3,f4;
	f1=f2=f3=f4=0;
	if(s1==s2)
	{
		f1=1;
	}
	else f1=0;
	string t1=c1.substr(0,2);
	string t2=c2.substr(0,2);
	int i=c1.size()-1;
	if(t1==t2&&f1==1)
	{
		f2=1;
	}
	else f2=0;
	if(f2)
	{
		if(c1[i]=='A'&&(c2[i]=='B'||c2[i]=='C'))
			f3=1;
		if(c1[i]=='B'&&(c2[i]=='A'||c2[i]=='C'))
			f3=1;	
		if(c1[i]=='C'&&(c2[i]=='A'||c2[i]=='B'))
			f3=1;
		if(c1[i]=='D'&&c2[i]=='E')
			f3=1;
		if(c1[i]=='E'&&c2[i]=='D')
			f3=1;
	}
	if(f3)
	{
		if(abs(c1[i]-c2[i])==1&&!(c1[i]=='C'&&c2[i]=='D'))
			f4=1;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
