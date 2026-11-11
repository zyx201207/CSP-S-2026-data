#include <bits/stdc++.h>
using namespace std;

string n,m,x,y,m1,y2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>n>>m>>x>>y;
	
	
	m1=m[0]+m[1];
	y2=y[0]+y[1];
	
	if(n==x) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	
	if(m1==y2) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	
	if(m[2]=='F'||m[2]=='D')
		if(y[2]=='F'||y[2]=='D') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	else if(m[2]=='A'||y[2]=='A')
		if(y[2]=='B'||m[2]=='B'||y[2]=='C'||m[2]=='C') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	else if(m[2]=='B'||y[2]=='B')
		if(y[2]=='A'||m[2]=='A'||y[2]=='C'||m[2]=='C') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	else if(m[2]=='C'||y[2]=='C')
		if(y[2]=='B'||m[2]=='B'||y[2]=='A'||m[2]=='A') cout<<1;
		else{
			cout<<"00";
			return 0;
		}
	
	if(m[2]=='F'||m[2]=='D')
		if(y[2]=='F'||y[2]=='D') cout<<1;
		else{
			cout<<0;
			return 0;
		}
	else if(m[2]=='A'||y[2]=='A')
		if(y[2]=='B'||m[2]=='B') cout<<1;
		else{
			cout<<0;
			return 0;
		}
	else if(m[2]=='B'||y[2]=='B')
		if(y[2]=='A'||m[2]=='A'||y[2]=='C'||m[2]=='C') cout<<1;
		else{
			cout<<0;
			return 0;
		}
	else if(m[2]=='C'||y[2]=='C')
		if(y[2]=='B'||m[2]=='B') cout<<1;
		else{
			cout<<0;
			return 0;
		}
	
}
