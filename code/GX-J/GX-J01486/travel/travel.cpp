#include<bits/stdc++.h>
using namespace std;
	string s1,s2,t1,t2;
	bool q=true;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>t1>>t2;
	if(s1==t1)
	{
		cout<<"1";
		for(int i=0;i<2;i++)
		{
			if(s2[i]!=t2[i])
			{
				q=false;
				break;
			}	
		}
		if(q)
		{
			cout<<"1";
			if(s2[2]<='C')
			{
				if(t2[2]<='C')
				{
					cout<<"1";
					if(s2[2]+1==t2[2] || s2[2]-1==t2[2])
					cout<<"1";
					else
					cout<<"0";
				}
				else
				{
					cout<<"00";
				}
			}
			else
			{
				if(t2[2]>'c')
				{
					cout<<"11";
					//if(s2[2]+1==t2[2] || s2[2]-1==t2[2])
					//cout<<"1";
					//else
					//cout<<"0";
				}
				else
				{
					cout<<"00";
				}
			}
		}
		else
		cout<<"000";
		
	}
	else
	cout<<"0000";
	
	return 0;
}
