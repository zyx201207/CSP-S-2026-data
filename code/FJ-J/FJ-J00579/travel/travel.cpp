#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("travel.in");
	ofstream fout("travel.out");
	int r1,x1;
	string r2,x2;
	fin>>r1>>r2>>x1>>x2;
	if(r1==x1)
	{
		fout<<"1";
	}
	else
	{
		fout<<"0000";
		return 0; 
	}
	if(r2[0]==x2[0]&&r2[1]==x2[1])
	{
		fout<<"1";
	}
	else
	{
		fout<<"000";
		return 0;
	}
	if((x2[2]=='D'&&r2[2]=='F')||(r2[2]=='D'&&x2[2]=='F'))
	{
		fout<<"11";
		return 0;
	}
	if(x2[2]>='A'&&x2[2]<='C'&&r2[2]>='A'&&r2[2]<='C')
	{
		fout<<"1";
	}
	else
	{
		fout<<"00";
		return 0;
	}
	if(x2[2]-r2[2]==1||x2[2]-r2[2]==-1)
	{
		fout<<"1";
	}
	else
	{
		fout<<"0";
	}
	return 0;
}
