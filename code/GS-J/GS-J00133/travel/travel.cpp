#include <iostream>
using namespace std;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	
	if (c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if (s1[0]==s2[0] && s2[1]==s2[1]){
		cout<<"1";
	}
	if (s1[2]=="A" && s2[2]=="B"){
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if (s1[2]=="B" && s2[2]=="C"){
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if (s1[2]=="D" && s2[2]=="F"){
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	
	
	return 0;
}
