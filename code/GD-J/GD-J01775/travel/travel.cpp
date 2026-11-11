#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>d>>c;
	if(a==d){
		cout<<"1";
		if(b[0]==c[0]&&b[1]==c[1]){
			cout<<"1";
			if(b[2]=='F'&&c[2]=='D'||b[2]=='D'&&b[2]=='F')cout<<"11";
			else if(b[2]>='A'&&b[2]<='C'&&c[2]<='C'&&c[2]>='A'){
				cout<<"1";
				if(b[2]=='A'&&c[2]=='B'||b[2]=='B'&&c[2]=='C'||b[2]=='B'&&c[2]=='A'||b[2]=='C'&&c[2]=='B')cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
