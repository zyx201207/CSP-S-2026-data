#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<'1';
		if(c[0]==d[0]&&c[1]==d[1]){
			cout<<'1';
			if(c[2]=='A'&&d[2]=='D') cout<<'0'<<'0';
			else if(c[2]=='A'&&d[2]=='F') cout<<'0'<<'0';
			else if(c[2]=='B'&&d[2]=='D') cout<<'0'<<'0';
			else if(c[2]=='B'&&d[2]=='F') cout<<'0'<<'0';
			else if(c[2]=='C'&&d[2]=='D') cout<<'0'<<'0';
			else if(c[2]=='C'&&d[2]=='F') cout<<'0'<<'0';
			else if(c[2]=='D'&&d[2]=='A') cout<<'0'<<'0';
			else if(c[2]=='D'&&d[2]=='B') cout<<'0'<<'0';
			else if(c[2]=='D'&&d[2]=='C') cout<<'0'<<'0';
			else if(c[2]=='F'&&d[2]=='A') cout<<'0'<<'0';
			else if(c[2]=='F'&&d[2]=='B') cout<<'0'<<'0';
			else if(c[2]=='F'&&d[2]=='C') cout<<'0'<<'0';
			else {
				cout<<'1';
				if(c[2]=='A'&&d[2]=='B') cout<<'1';
				else if(c[2]=='B'&&d[2]=='A') cout<<'1';
				else if(c[2]=='B'&&d[2]=='C') cout<<'1';
				else if(c[2]=='C'&&d[2]=='B') cout<<'1';
				else if(c[2]=='D'&&d[2]=='F') cout<<'1';
				else if(c[2]=='F'&&d[2]=='D') cout<<'1';
				else cout<<'0';
			}
			
		} 
		else cout<<'0'<<'0'<<'0';
	} 
	else cout<<'0'<<'0'<<'0'<<'0';
	return 0;
}