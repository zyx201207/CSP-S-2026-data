#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{
		cout<<"1";
		if(a2[0]==b2[0]&&a2[1]==b2[1])
		{
			cout<<"1";
			char f1=a2[2],f2=b2[2];
			if(f1=='A'&&(f2=='B'||f2=='C'))cout<<"1";
			else if(f1=='B'&&(f2=='A'||f2=='C'))cout<<"1";
			else if(f1=='C'&&(f2=='A'||f2=='B'))cout<<"1";
			else if(f1=='D'&&f2=='F')cout<<"1";
			else if(f1=='F'&&f2=='D')cout<<"1";
			else cout<<"0";
			if(f1=='A'&&f2=='B')cout<<"1";
			else if(f1=='B'&&(f2=='A'||f2=='C'))cout<<"1";
			else if(f1=='C'&&f2=='B')cout<<"1";
			else if(f1=='D'&&f2=='F')cout<<"1";
			else if(f1=='F'&&f2=='D')cout<<"1";
			else cout<<"0";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
