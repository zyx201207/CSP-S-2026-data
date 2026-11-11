#include<bits/stdc++.h>
#define int long long
using namespace std;
bool q1,q2,q3,q4;
string c1;
string c2;
signed main()
{
	string s1;
	string s2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=c1.size();i++)
	{
		if(c1[i]==c2[i])
		{
			q1=1;
		}
		else
		{
			cout<<"0000";
			return 0;
		}
	}//判断车厢是否相同
	for(int i=0;i<2;i++)
	{
		if(s1[i]==s2[i])
		q2=1;
		else
		{
			cout<<"1000";
			return 0;
		}
	}
	    
		if(s1[2]>='A'&&s1[2]<='C')
		{
			if(s2[2]>='A'&&s2[2]<='C')
			{
				q3=1;
				if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)
				{
					cout<<"1111";
					return 0;
				}
				else{
					cout<<"1110";
					return 0;
				}
			}
			else{
				cout<<"1100";
				return 0;
			}
		}
		else if(s1[2]=='D'&&s1[2]=='F'){
			if(s2[2]=='D'&&s2[2]=='F')
			{
				cout<<"1111";
				return 0;
			}
			else{
				cout<<"1100";
			}
		}
	return 0;
}
/*http://172.16.77.83:8888/student/*/
/*ccfloveyou*/
/*Trick||Treat!*/