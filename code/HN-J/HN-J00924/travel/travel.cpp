#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int q1,q2,q3,q4;
    char b,i;
	char n,m,q,w,s,a,p,o;
	cin>>n>>m>>s>>a>>b>>q>>w>>p>>o>>i;
	if(n==q&&m==w)
	{
		q1==1;
		if(s==p&&a==o)
		{
			q2==1;
			if((b=='F'&&i=='D')||(b=='D'&&i=='F')||(b=='C'&&i=='B')||(b=='C'&&i=='A')||(b=='B'&&i=='C')||(b=='A'&&i=='C')||(b=='B'&&i=='A')||(b=='A'&&i=='B')){
				q3==1;
				if(b=='A'&&i=='B'||b=='B'&&i=='A'||b=='B'&&i=='C'||b=='C'&&i=='B'||b=='D'&&i=='F'||b=='F'&&i=='D')
				{
					cout<<1111;
				}
				else cout<<1110;
			}
			else cout<<1100;
		}
		else cout<<1000;
	}
	else cout<<"0000";
	return 0;
 }  
