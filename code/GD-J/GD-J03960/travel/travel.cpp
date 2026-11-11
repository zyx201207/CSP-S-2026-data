#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,ai,bi;
	cin>>a>>b>>ai>>bi;
	if(a==ai)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==bi[0]&&b[1]==bi[1])cout<<1; 
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]=='F'&&bi[2]=='D')cout<<11;
	else if(b[2]=='D'&&bi[2]=='F')cout<<11;	
	else if(b[2]=='A'&&bi[2]=='B')cout<<11;
	else if(b[2]=='B'&&bi[2]=='A')cout<<11;
	else if(b[2]=='B'&&bi[2]=='C')cout<<11;
	else if(b[2]=='C'&&bi[2]=='B')cout<<11;
	else if(b[2]=='A'&&bi[2]=='C')cout<<10;
	else if(b[2]=='C'&&bi[2]=='A')cout<<10;
	else cout<<"00";
	return 0;
}
