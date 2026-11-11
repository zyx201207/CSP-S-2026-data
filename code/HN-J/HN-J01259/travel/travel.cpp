#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cr,cx;
	string sr,sx;
	cin >> cr >> sr >> cx >> sx;
	if(cr==cx)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	//车厢 
	if(sr[0]==sx[0])
	{
		if(sr[1]==sx[1])
		{
			cout << 1;
		}
		else
		{
			cout << 0 << 0;
		}
	}
	else
	{
		cout << 0 << 0;
	}
	//排数
	if(sr[2]=='F'&&sx[2]=='D'||sr[2]=='D'&&sr[2]=='F')
	{
		cout << 1 << 1;
	}
	else if('A' <= sr[2]&&'C' >= sr[2]&&'A' <= sx[2]&&'C' >= sx[2])
	{
		cout << 1;
	}
	else
	{
		cout << 0; 
	} 
	//同一侧
	if('A' <= sr[2]&&'C' >= sr[2]&&'A' <= sx[2]&&'C' >= sx[2])
	{
		if(sr[2]+1==sx[2]||sr[2]-1==sx[2])
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		cout << 0;
	}
	//如果在下面，则判断在一起
		 

	
	return 0;	
} 
