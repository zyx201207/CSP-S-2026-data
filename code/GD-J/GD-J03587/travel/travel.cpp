#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a1=0,a2=0;
	for(int i=0;i<2;i++)
	{
		a1 = a1 * 10 + c1[i] - 48;
		a2 = a2 * 10 + c2[i] - 48;
	}	
	if(a1 == a2)
	{
		cout<<1;
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			cout<<1;
			int left = 0,right = 0;
			if(s1[2] <= 'C') left++;
			else right++;
			if(s2[2] <= 'C') left ++;
			else right++;
			if(left && right)
			{
				cout<<"00";
			}
			else
			{
				cout<<1;
				if(abs(s1[2] - s2[2]) == 1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
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
	return 0;
} 
