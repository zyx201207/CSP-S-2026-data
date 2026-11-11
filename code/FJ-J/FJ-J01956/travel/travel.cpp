#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		char cc1=s1[0],cc3=s1[1],cc2=s2[0],cc4=s2[1];
		int ss1=(cc1-'0')*10+(cc3-'0');
		int ss2=(cc2-'0')*10+(cc4-'0');
		if(ss1!=ss2)
		{
			cout<<"1000";
			return 0;
		}
		else
		{
			int cs1=s1[2]-'A',cs2=s2[2]-'A';
			if((cs1<=2&&cs2>=3)||(cs2<=2&&cs1>=3))
			{
				cout<<"1100";
				return 0;
			}
			else
			{
				if(abs(cs1-cs2)==1)
				{
					cout<<"1111";
					return 0;
				}
				else
				{
					cout<<"1110";
					return 0;
				}
			}
		}
	}
	return 0;
} 
