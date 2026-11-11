#include<bits/stdc++.h>
using namespace std;
int c1[10],s1[10],c2[10],s2[10];
int main()
{
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1[10]>>c2[10]>>s1[10]>>s2[10];
	if(c1!=c2)
    {
    	cout <<"0000";
	}
	else
	{
		cout <<"1";
		if(s2[0]==s1[0] || s1[1]==s2[1])
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	
	}
	return 0; 
}
