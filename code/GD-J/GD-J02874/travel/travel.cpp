#include<bits/stdc++.h>
using namespace std;
long long a,b;
string aa,bb; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	if(a != b)
	{
		cout<<"0000";
	}
	else if(aa[0] != bb[0] or aa[1] != bb[1])
	{
		cout<<"1000";
	}
	else if(aa[2] >'C' and bb[2] <= 'C' or aa[2] <= 'C' and bb[2] >'C')
	{
		cout<<"1100"; 
	}
	else if(char(aa[2] + 1) == bb[2] or char(aa[2] - 1) == bb[2])
	{
		cout<<"1111";
	}
	else	
	{
		cout<<"1110";
	}
	return 0;
}
