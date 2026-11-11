#include<iostream>
using namespace std;
string c,s,x,y;
int main()
{ 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>x>>y;
	if(c==x)
	{
		cout<<1;
		if(s[0]==y[0]&&s[1]==y[1])
		{
			cout<<1;
			if('A'<=s[2]&&s[2]<='C'&&'A'<=y[2]&&y[2]<='C')
			{
				cout<<1;
				if(s[2]+1==y[2]||s[2]-1==y[2])cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	
} 
