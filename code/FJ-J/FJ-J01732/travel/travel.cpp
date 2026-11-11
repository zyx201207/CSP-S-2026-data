#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f(char x)
{
	if(x=='A' || x=='B' || x=='C') return 1;
	else return 0;
}
bool ok(char x,char y)
{
	char c=x;
	x=min(x,y),y=max(y,c);
	if(x=='A' && y=='B') return 1;
	if(x=='B' && (y=='A' || y=='C')) return 1;
	if(x=='D' && y=='F') return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			cout<<1;
			bool f1=f(s1[2]),f2=f(s2[2]);
			if(f1==f2)
			{
				cout<<1;
				if(ok(s1[2],s2[2])) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
