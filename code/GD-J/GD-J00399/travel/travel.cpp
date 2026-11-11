#include <bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int seat1_ = 0,seat2_ = 0;
	char seat1,seat2;
	
	for(int i=0;i<2;i++)
	{
		seat1_ = seat1_*10 + (s1[i] - '0');
		seat2_ = seat2_*10 + (s2[i] - '0');
	}
	seat1 = s1[2];
	seat2 = s2[2];
	set<char> st;
	st.insert(s1[2]);
	st.insert(s2[2]);
	
	if(c1 == c2)
	{
		cout<<1;
		
		if(seat1_ == seat2_)
		{
			cout<<1;
			if(seat1 > seat2) swap(s1[2],s2[2]);
			
			if(((st.count('A') || st.count('B') || st.count('C')) && (!st.count('D') && !st.count('F'))) || (s1[2] == 'D' && s2[2] == 'F'))
			{
				cout<<1;
				
				if(s1[2] + 1 == s2[2])
				{
					cout<<1;
					return 0;
				}
				else
				{
					cout<<"0"<<endl;
					return 0;
				}
			}
			else
			{
				cout<<"00"<<endl;
				return 0;
			}
		}
		else
		{
			cout<<"000"<<endl;
			return 0;
		}
	}
	else
	{
		cout<<"0000"<<endl;
		return 0;
	}
	
	return 0;
}
