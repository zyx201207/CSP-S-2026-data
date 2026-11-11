#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f(string x)
{
	if(x[2]=='A') return 1;
	else if(x[2]=='B') return 2; 
	else if(x[2]=='C') return 3; 
	else if(x[2]=='D') return 4; 
	else if(x[2]=='E') return 5;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]) cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	int pos1=f(b),pos2=f(d);
	if((pos1<=3&&pos2<=3)||(pos1>=4&&pos2>=4)) cout<<"1";
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(pos1-pos2)==1) cout<<"1";
	else cout<<"0";
	return 0;
}
