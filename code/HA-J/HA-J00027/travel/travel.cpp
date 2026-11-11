#include<bits/stdc++.h>
using namespace std;

#define ll long long

string xx,yy,ans,x,y;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>x>>xx>>y>>yy;
	//1. 
	if(x==y) ans+='1';
	else ans+='0';
	//2. 
	if(x==y&&xx[0]+xx[1]==yy[0]+yy[1]) ans+='1';
	else ans+='0';
	//3.
	bool cx=0,cy=0;
	if(xx[2]=='A'||xx[2]=='B'||xx[2]=='C') cx=1;
	else cx=0;
	if(yy[2]=='A'||yy[2]=='B'||yy[2]=='C') cy=1;
	else cy=0;
	if(x==y&&(xx[0]+xx[1]==yy[0]+yy[1])&&cx==cy) ans+='1';
	else ans+='0';
	//4.
	int t=(xx[2]-'A'),tt=(yy[2]-'A');
	if(x==y&&xx[0]+xx[1]==yy[0]+yy[1]&&cx==cy&&abs(t-tt)==1) ans+='1';
	else ans+='0';
	cout<<ans;
	return 0;
}
