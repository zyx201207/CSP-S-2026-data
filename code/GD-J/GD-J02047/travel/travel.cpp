#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s1, s2, s3, s4;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)//同一节车厢 
	{
		cout<<1;
		if(s2[0]==s4[0]&&s2[1]==s4[1])//同一排 
		{
			cout<<1;
			if((s2[2]<='C'&&s4[2]<='C')||(s2[2]>='D'&&s4[2]>='D'))
			{
				cout<<1;
				if(abs(s2[2]-s4[2])==1)
				{
					cout<<1;
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	cout<<'\n';
	return 0;
}

