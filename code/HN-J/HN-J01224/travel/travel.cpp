#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1,s2,t1,t2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char w='A',t='B',e='C',u='D',q='F';
	cin>>c1>>s1>>t1>>c2>>s2>>t2;
	if(c1==c2&&s1==s2&&t1==u&&t2==q)
	{
		cout<<"1111";
	}
	else if(c1==c2&&s1==s2&&t1==q&&t2==u)
	{
		cout<<"1111";
	}
	else if(c1==c2&&s1==s2&&t1==w&&t2==t)
	{
		cout<<"1111";
	}
	else if(c1==c2&&s1==s2&&t1==t&&t2==w)
	{
		cout<<"1111";
	}
	else if(c1==c2&&s1!=s2)
	{
		cout<<"1000";
	}
	else if(c1==c2&&s1==s2&&t1==w||t1==t||t1==e&&t2==u||t2==q)
	{
		cout<<"1100";
	}
	else if(t1==w&&t2==e)
	{
		cout<<"1110";
	} 
	else if(t1==e&&t2==w)
	{
		cout<<"1110";
	}
	else
    {
    	cout<<"0000"; 
	}
	return 0;
}
