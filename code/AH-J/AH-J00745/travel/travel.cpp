#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,a1,b1;
	char a2,b2;
	cin>>a>>a1>>b>>b1;
	a2=a1[2];
	b2=b1[2];
	a1.erase(2,1);
	b1.erase(2,1);
	if(a==b)
	{
		cout<<1;
		if(a1==b1)
		{
			cout<<1;
			if((a2=='A'||a2=='B'||a2=='C')+(b2=='D'||b2=='F')==1)
			{
				cout<<1;
				if((int(a2)-int(b2)==-1||int(a2)-int(b2)==1))
				{
					cout<<1;
				}
				else
				{
					cout<<0;
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
	return 0;
}
