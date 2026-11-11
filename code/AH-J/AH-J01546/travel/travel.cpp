#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long a1,a2,b1,b2,d1,d2,e1,e2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	b1=s1[0]-'0';
	b2=s2[0]-'0';
	d1=s1[1]-'0';
	d2=s2[1]-'0';
	e1=s1[2]-'A';
	e2=s2[2]-'A';
	if(a1==a2)
	{
		cout<<1;
		if(b1==b2&&d1==d2)
		{
			cout<<1;
			if((e1<=2&&e2<=2)||(e1>2&&e2>2))
			{
				cout<<1;
					if(abs(e1-e2)==1)
					cout<<1;
					else
					cout<<0;
			}
			else
			cout<<"00";
		}	
		else
		cout<<"000";
	}
	else
	cout<<"0000";
}
