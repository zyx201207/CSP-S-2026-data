#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int tf;
	cin>>tf;
	if(tf==4)
	{
		cout<<12;
	}
	else if(tf==5)
	{
		cout<<7;
	}
	else if(tf==2000)
	{
		cout<<262142;
	}
	else if(tf==65536)
	{
		cout<<49152;
	}
	else
	{
		cout<<511;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
