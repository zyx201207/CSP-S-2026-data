#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	cin>>c1>>c2>>s1>>s2;
	{
		if(c1==c2)
			cout<<"1"<<endl;
		else
			cout<<"0000"<<endl;
	}
	{
		if(s1[1]==s2[1])
			cout<<"111"<<endl;
		else
			cout<<"000"<<endl;
	}
	if(s1[3]==A and s2[3]==B)
		cout<<"11"<<endl;
	else if(s1[3]==B and s2[3]==A)
		cout<<"11"<<endl;
	else if(s1[3]==B and s2[3]==C)
		cout<<"11"<<endl;
	else if(s1[3]==C and s2[3]==B)
		cout<<"11"<<endl;
	else if(s1[3]==F and s2[3]==D)
		cout<<"11"<<endl;
	else if(s1[3]==D and s2[3]==F)
		cout<<"11"<<endl;
	else
		cout<<"00"<<endl;\
	return 0;	
}
