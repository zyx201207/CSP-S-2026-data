#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int ans1,ans2,ans3,ans4;
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2)
		ans1 = 1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1])
		ans2 = 1;
	else
	{
		cout<<"1000";
		return 0;
	}
	if(s1[2] - 'A' <= 2 && s2[2] - 'A' <= 2)
	{
		ans3 = 1;
	}	
	else if(s1[2]-'A'>2 && s2[2]-'A'>2)
	{
		ans3 = 1;
	}
	else
	{
		cout<<"1100";
		return 0;
	}
	if(abs(s1[2]-s2[2]) == 1)
			ans4 = 1;
	else
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;	
} 
