#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
bool solve1()
{
	return c1==c2;
}
bool solve2()
{
	return solve1()&&s1.substr(0,2)==s2.substr(0,2);
}
bool solve3()
{
	bool beside;
	if(s1[2]=='F'||s1[2]=='D')
		if(s2[2]=='F'||s2[2]=='D')
			beside=true;
		else
			beside=false;
	else
		if(s2[2]=='F'||s2[2]=='D')
			beside=false;
		else
			beside=true;
	return solve2()&&beside;
}
bool solve4()
{
	bool flag;
	if(s1[2]=='F')
		if(s2[2]=='D')
			flag=true;
		else
			flag=false;
	else if(s1[2]=='D')
		if(s2[2]=='F')
			flag=true;
		else
			flag=false;
	else if(s1[2]=='C')
		if(s2[2]=='B')
			flag=true;
		else
			flag=false;
	else if(s1[2]=='B')
		if(s2[2]=='A'||s2[2]=='C')
			flag=true;
		else
			flag=false;
	else
		if(s2[2]=='B')
			flag=true;
		else
			flag=false;
	return solve2()&&flag;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	cout<<solve1()<<solve2()<<solve3()<<solve4();
	return 0;
}
