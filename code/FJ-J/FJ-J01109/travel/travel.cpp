#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1==c2)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	
	int t1=('A'<=s1[2]&&s1[2]<='C')?1:0;
	int t2=('A'<=s2[2]&&s2[2]<='C')?1:0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&t1==t2)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&t1==t2&&abs(s1[2]-s2[2])==1)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	printf("\n");
	return 0;
}
