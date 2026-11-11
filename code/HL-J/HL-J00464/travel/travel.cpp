#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(b[2]>=65 && b[2]<=67)x=1;
	else x=0;
	if(d[2]>=65 && d[2]<=67)y=1;
	else y=0;
	
	
	
	if(a==c)cout<<"1";
	else {
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	
	if(b[0]==d[0] && b[1]==d[1])cout<<"1";
	else{
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	
	if(x==y)cout<<"1";
	else{
		cout<<"0";
		cout<<"0";
		return 0;
	}
	
	if(b[2]+1==d[2] || b[2]-1==d[2])cout<<"1";
	else cout<<"0";
	return 0;
}
