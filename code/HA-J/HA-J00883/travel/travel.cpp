#include<bits/stdc++.h>
using namespace std;
int cr,cx;
string sr,sx;
bool flag = false,train = false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr;
	for(int i = 1;i <= 3;i++)
	{
		cin>>sr[i];
	}
	cin>>cx;
	for(int i = 1;i <= 3;i++)
	{
		cin>>sx[i];
	}
	if(cr == cx)
	{
		cout<<1;
		train = true;
	}
	else
	{
		cout<<0;
	}
	if((int(sr[1] * 10 + sr[2]) == int(sx[1] * 10 + sx[2])) && train == true)
	{
		cout<<1;
		flag = true;
	}
	else
	{
		cout<<0;
	}
	if(((sr[3] <= 'C' && sx[3] <= 'C') || ((sr[3] <= 'F' && sr[3] >= 'D') && (sr[3] <= 'F' && sr[3] >= 'D')))&& flag == true && train == true)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if((sr[3] + 1 == sx[3]) || (sx[3] + 1 == sr[3]))
	{
		if(sr[3] == 'C' && sx[3] == 'D')
		{
			cout<<0;
		}
		else if(flag == false)
		{
			cout<<0;
		}
		else
		{
			cout<<1;
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
}
