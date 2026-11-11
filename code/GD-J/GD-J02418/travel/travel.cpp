#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin;
	fin.open("travel.in",ios::in);
	ofstream fout;
	fout.open("travel.out",ios::out);
	string s1,a1;
	string s2,a2;
	fin>>a1;
	fin>>s1;
	fin>>a2;
	fin>>s2;
	int s1flag,s2flag;
	if(s1[2] == 'F' || s1[2] == 'D')
	{
		s1flag = 1;
	}
	else
	{
		s1flag = 0;
	}
	if(s2[2] == 'F' || s2[2] == 'D')
	{
		s2flag = 1;
	}
	else
	{
		s2flag = 0;
	}
	if(a1[0] == a2[0] && a1[1] == a2[1])
	{
		fout<<"1";
	}
	else
	{
		fout<<"0000";
		return 0;
	}
	if(s1[0] == s2[0]&&s1[1] == s2[1])
	{
		fout<<"1";
	}
	else
	{
		fout<<"000";
		return 0;
	}
	if(s1flag == s2flag)
	{
		fout<<"1";
	}
	else
	{
		fout<<"00";
		return 0;
	}
	if(s1[2] == s2[2] - 1||s1[2] == s2[2] + 1)
	{
		fout<<"1";
	}
	else
	{
		fout<<"0";
	}
	return 0;
} 
