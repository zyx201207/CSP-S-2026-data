#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string S1=s1,S2=s2;
	S1.pop_back();
	S2.pop_back();
	char C1=s1.back();
	char C2=s2.back();
	if(c1==c2)
	{
		cout<<1;
		if(S1==S2)
		{
			cout<<1;
			if('A'<=C1&&C1<='C'&&'A'<=C2&&C2<='C')
			{
				cout<<1;
				if(C2==C1+1||C1==C2+1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else if('D'<=C1&&C1<='F'&&'D'<=C2&&C2<='F')
			{
				cout<<1;
				if(C2==C1+2||C1==C2+2)
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
				cout<<0;
				cout<<0;
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
}
