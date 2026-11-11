#include<bits/stdc++.h>
using namespace std;
int cr,cx;
string sr,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr!=cx)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
		if(sr[0]!=sx[0]||sr[1]!=sx[1])
		{
			cout<<"000";
			return 0;
		}
		else
		{
			cout<<"1";
			if((sr[2]=='C'&&sx[2]=='D')||(sx[2]=='C'&&sr[2]=='D'))
			{
				cout<<"00";
				return 0;
			}
			if(('A'<=sr[2]<='C')&&('A'<=sx[2]<='C'))
			{
				cout<<"1";
				if(sr[2]+1==sx[2]||sr[2]-1==sx[2])  cout<<"1";
				else  cout<<"0";
			}
			else  if((sr[2]=='D'&&sx[2]=='F')||(sx[2]=='D'&&sr[2]=='F'))  cout<<"11";
			else  cout<<"00";
		}
	}
	return 0;
} 
