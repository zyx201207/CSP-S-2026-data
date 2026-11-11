#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const int N=1000000+7;
int a1,b1;
string a2,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a1;
	cin>>a2;
	cin>>b1;
	cin>>b2;
	//cout<<a1<<a2[2]<<b1<<b2;
	int a3=a2[0]*10+a2[1];
	int b3=b2[0]*10+b2[1];
	int a=a2[2],b=b2[2];
	if(a1==b1)
	{
		cout<<"1";
		if(a3==b3)
		{
			cout<<"1";
			if(a>=68&&b>=68)
			{
				cout<<"11";
				return 0;
			}
			if(a<=67&&b<=67)
			{
				cout<<"1";
				int c=max(a,b);
				int d=min(a,b);
				if(d+1==c)
				{
					cout<<"1";
					return 0;
				}
				else
				{
					cout<<"0";
					return 0;
				}
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else
	{
		cout<<"0000"; 
		return 0;
	}
	return 0;
}
