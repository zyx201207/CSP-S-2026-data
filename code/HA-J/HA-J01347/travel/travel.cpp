#include <bits/stdc++.h>
using namespace std;
int C1,C2;
string S1,S2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>C1;
	cin>>S1;
	cin>>C2;
	cin>>S2;
	string X="ABCDF";
	if (C1==C2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if (S1[0]==S2[0] && S1[1]==S2[1])
	{
		cout<<"1"; 
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if ((S1[2]==X[0] || S1[2]==X[1] || S1[2]==X[2]) && (S2[2]==X[0] || S2[2]==X[1] || S2[2]==X[2]))
	{
		cout<<"1";
	}
	else if ((S1[2]==X[3] || S1[2]==X[4]) && (S2[2]==X[3] || S2[2]==X[4]))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if (((S1[2]==X[0] && S2[2]==X[1]) && (S1[2]==X[1] || S2[2]==X[2]) && (S1[2]==X[3] || S2[2]==X[4])) || ((S2[2]==X[0] && S1[2]==X[1]) && (S2[2]==X[1] || S1[2]==X[2]) && (S2[2]==X[3] || S1[2]==X[4])))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		return 0;
	}
	return 0;
} 

