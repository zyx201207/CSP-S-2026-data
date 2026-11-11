#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<"1";
	else if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	int a,b;
	a=int(s1[0]-'0')*10+int(s1[1]-'0');
	b=int(s2[0]-'0')*10+int(s2[1]-'0');
	
	if(a==b)
		cout<<"1";
	else if(a!=b)
	{
		cout<<"000";
		return 0;
	}
	char c,d;
	c=s1[2];
	d=s2[2];
	if((c=='A'&&d=='B')||(c=='A'&&d=='C'))
	cout<<"1";
	else if((c=='B'&&d=='A')||(c=='B'&&d=='C'))
	cout<<"1";
	else if((c=='C'&&d=='A')||(c=='C'&&d=='B'))
	cout<<"1";
	else if(c=='D'&&d=='F')
	cout<<"1";
	else if(c=='F'&&d=='D')
	cout<<"1";
	else
	{
		cout<<"00";
		return 0;
	}
	if(c=='A'&&d=='B')
		cout<<"1";
	else if((c=='B'&&d=='A')||(c=='B'&&d=='C'))
	cout<<"1";
	else if(c=='C'&&d=='B')
	cout<<"1";
	else if(c=='D'&&d=='F')
	cout<<"1";
	else if(c=='F'&&d=='D')
	cout<<"1";
	else
	    cout<<"0";
	return 0;
}
