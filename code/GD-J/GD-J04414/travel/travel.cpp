#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define logn long
#define itn int
using namespace std;
string a,b,x,y;
int main(){
	fre("travel");
	cin>>a>>x>>b>>y;
	if(a==b)cout<<"1";
	else cout<<"0000",exit(0);
	if(x[0]==y[0] and x[1]==y[1])cout<<"1";
	else cout<<"000",exit(0);
	if((x[2]<='C' and y[2]<='C' and x[2]>='A' and y[2]>='A') or ((x[2]=='D' and y[2]=='F') or (x[2]=='F' and y[2]=='D')))cout<<"1";
	else cout<<"00",exit(0);
	if(abs(x[2]-y[2])==1 or ((x[2]=='D' and y[2]=='F') or (x[2]=='F' and y[2]=='D')))cout<<"1";
	else cout<<"0",exit(0);
	return 0;
}

