#include<bits/stdc++.h>
#include<cstring>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		printf("0000");
		return 0;
	}
	else
		printf("1");
	if(s1[0]==s2[0]&&s1[1]==s2[1])
		printf("1");
	else
	{
		printf("000");
		return 0;
	}
	string a=s1.substr(2,1),b=s2.substr(2,1);
	if((a=="A"&&b=="B")||(a=="A"&&b=="C")||(a=="B"&&b=="A")||(a=="B"&&b=="C")||(a=="C"&&b=="A")||(a=="C"&&b=="B")||(a=="D"&&b=="E")||(a=="E"&&b=="D"))
		printf("1");
	else
	{
		printf("00");
		return 0;
	}
	if((a=="A"&&b=="B")||(a=="B"&&b=="A")||(a=="B"&&b=="C")||(a=="C"&&b=="B")||(a=="D"&&b=="E")||(a=="E"&&b=="D"))
		printf("1");
	else
		printf("0");
	return 0;
}
