#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1!=c2)
	{
	    cout << "0000";
	}
	else
	{
		cout << "1";
	}
	string a[5]=s1,b[5]=s2;
	for(int i=1;i<=3;i++)
	{
	    a[i]=s1[i];
	    b[i]=s2[i];
	}
	if(c1==c2)
	{
	    if(a[1]==b[0])
		{
			cout << "1";
		}
		else
		{
			cout << "000";
		}
	}
	
	return 0; 
} 
