#include<bits/stdc++.h>
using namespace std;
bool find1(string s1,string s2,string c1,string c2)//是否在同一节车厢的同一排
{
	if(c1!=c2)
		return false;
	if(s1[0]==s2[0] && s1[1]==s2[1])
		return true;
	else
		return false;
}
bool find2(string s1,string s2,string c1,string c2)//是否在同一节车厢的同一排，且位于过道的同一侧
{
	if(find1(s1,s2,c1,c2))	
	{
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='C'&&s2[2]=='A'))
			return true;
		else if((s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D'))
			return true;
		else
			return false;
	}
	return false;
	
}
bool find3(string s1,string s2,string c1,string c2)//座位是否相邻
{
	if(find2(s1,s2,c1,c2))
		if(s1[2]+1==s2[2] || s1[2]-1==s2[2])
			return true;
		else
			return false;
	else
		return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)
		cout << 1;
	else
		cout << 0;
	if(find1(s1,s2,c1,c2))
		cout << 1;
	else
		cout << 0;
	if(find2(s1,s2,c1,c2))
		cout << 1 ;
	else
		cout << 0;
	if(find3(s1,s2,c1,c2))
		cout << 1;
	else
		cout << 0;
	return 0;
}
