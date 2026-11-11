#include<iostream>
#include<string>
using namespace std;
bool q1(char a,char b)
{
	if(a=='D') return (b=='F');
	else if(a=='F') return (b=='D');
	else return (b!='F'&&b!='D');
}
bool q2(char a,char b)
{
	if(a=='A'||a=='C') return (b=='B');
	else if(a=='B') return (b=='A'||b=='C');
	else if(a=='D') return (b=='F');
	else return (b=='D');
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			if(q1(s1[2],s2[2]))
			{
				cout<<1;
				if(q2(s1[2],s2[2])) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
