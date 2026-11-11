#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(b[1]==d[1])
	cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))
	cout<<"1";
	else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))
	cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(b[2]-'0'==d[2]-'1'||b[2]-'0'==d[2]+'1')
	cout<<"1";
	else
	cout<<"0";
	return 0;
 } 
