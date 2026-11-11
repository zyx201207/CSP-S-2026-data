#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long int b1,d1;
int main()
{
	ios::sync_with_stdio; 
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(b[2]=='A') b1=1;
	else if(b[2]=='B') b1=2;
	else if(b[2]=='C') b1=3;
	else if(b[2]=='D') b1=5;
	else if(b[2]=='F') b1=6;
	if(d[2]=='A') b[2]=1;
	else if(d[2]=='B') d1=2;
	else if(d[2]=='C') d1=3;
	else if(d[2]=='D') d1=5;
	else if(d[2]=='F') d1=6;
	if(a==c) cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(b[1]==d[1]&&b[0]==d[0]) cout<<"1";
	else cout<<"0";
	if(b[1]==d[1]&&b[0]==d[0]&&b1<=3&&d1<=3) cout<<"1";
	else if(b[1]==d[1]&&b[0]==d[0]&&b1>=5&&d1>=5) cout<<"1";
	else cout<<"0";
	if(b1-1==d1||b1+1==d1) cout<<"1";
	else cout<<"0";
	return 0; 
}
