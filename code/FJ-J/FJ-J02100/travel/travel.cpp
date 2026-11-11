#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
	cout<<"1";
	if(b[0]==d[0]&&b[1]==d[1]){
	cout<<"1";
	if(b[2]-'A'<=2&&d[2]-'A'<=2){
		cout<<"1";
		if(b[2]=='A'&&d[2]=='C'){
			cout<<"0";
		}
		else if(b[2]=='C'&&d[2]=='A'){
			cout<<"0";
		}
		else cout<<"1";
	}
	else if(b[2]-'A'>2&&d[2]-'A'>2){
		cout<<"11";
	}
	else cout<<"00";
	}
	else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}