#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1 != c2)
	{
		puts("0000");return 0;
	}
	if(s1[0] != s2[0] || s1[1] != s2[1])
	{
		puts("1000");return 0;
	}
	if(s1[2] <= 'C' && s2[2] >= 'D')
	{
		puts("1100");return 0;
	}
	if(s1[2] >= 'D' && s2[2] <= 'C')
	{
		puts("1100");return 0;
	}
	if(s1[2] == 'A' && s2[2] == 'C')
	{
		puts("1110");return 0;
	}
	if(s1[2] == 'C' && s2[2] == 'A')
	{
		puts("1110");return 0;
	}
	puts("1111");
	return 0;
}

