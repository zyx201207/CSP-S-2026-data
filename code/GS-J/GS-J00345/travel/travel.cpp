#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,q[100][10];
	cin>>c1>>s1>>c2>>s2;
	char m=s1[3],n=s2[3];
	for(int q=1;q<=c1.size();q++)
	{
		if(c1[q]==c2[q])
	    {
		    cout<<"1";
		
	    }
	    else
	    {
		    cout<<"0000";
		    return 0;
	    }
	}

	if(s1[1]==s2[1]&&s1[2]==s2[2])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	cout<<"0";
	cout<<"1";
	
}
	
	
	         

