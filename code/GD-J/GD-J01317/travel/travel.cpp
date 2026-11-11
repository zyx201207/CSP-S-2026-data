#include<bits/stdc++.h>
using namespace std;
int side(char c){
	if(c=='A'||c=='B'||c=='C')return 0;
	return 1;
}

int main(){
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if(side(b[2])==side(d[2])){
				cout<<"1";
				if(b[2]-d[2]==1 ||b[2]-d[2]==-1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0; 
}
