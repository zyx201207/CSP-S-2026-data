#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if(b[2]=='A'&&d[2]=='B')cout<<"11";
			if(b[2]=='A'&&d[2]=='C')cout<<"10";
			if(b[2]=='A'&&d[2]=='D')cout<<"00";
			if(b[2]=='A'&&d[2]=='F')cout<<"00";
			if(b[2]=='B'&&d[2]=='A')cout<<"11";
			if(b[2]=='B'&&d[2]=='C')cout<<"11";
			if(b[2]=='B'&&d[2]=='D')cout<<"00";
			if(b[2]=='B'&&d[2]=='F')cout<<"00";
			if(b[2]=='C'&&d[2]=='A')cout<<"10";
			if(b[2]=='C'&&d[2]=='B')cout<<"11";
			if(b[2]=='C'&&d[2]=='D')cout<<"00";
			if(b[2]=='C'&&d[2]=='F')cout<<"00";
			if(b[2]=='D'&&d[2]=='A')cout<<"00";
			if(b[2]=='D'&&d[2]=='B')cout<<"00";
			if(b[2]=='D'&&d[2]=='C')cout<<"00";
			if(b[2]=='D'&&d[2]=='F')cout<<"11";
			if(b[2]=='F'&&d[2]=='A')cout<<"00";
			if(b[2]=='F'&&d[2]=='B')cout<<"00";
			if(b[2]=='F'&&d[2]=='C')cout<<"00";
			if(b[2]=='F'&&d[2]=='D')cout<<"11";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	

} 
