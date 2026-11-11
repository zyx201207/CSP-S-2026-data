#include<bits/stdc++.h>
using namespace std;
string s1,y1,s2,y2;
long long cnt1,cnt2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>y1>>s2>>y2;
	if(s1!=s2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
		for(int i=0;i<=1;i++)
		{
			cnt1=cnt1+y1[i];
			cnt2=cnt2+y2[i];
		}
		if(cnt2!=cnt1)
		{
			cout<<"000";
			return 0;
		}
		else
		{
			cout<<"1";
			if(y1[2]<='C'&&y2[2]>'C'||y1[2]>='D'&&y2[2]<'D')
			{
				cout<<"00";
				return 0;
			}
			else
			{
				cout<<"1";
				if(abs(y1[2]-y2[2])!=1)
				{
					cout<<"0";
					return 0; 
				}
				else
				{
					cout<<"1";
					return 0;
				}
			}
		}
	}
	
	
	
	return 0;
} 
