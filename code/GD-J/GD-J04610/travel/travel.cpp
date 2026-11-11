#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in", 'r', stdin);
	freopen("travel.out", 'w', stdout);
	string a, b, c, d;
	int pp=0, qq=0;
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	if(b[2]>'C'){
		pp=1;
	}
	
	if(d[2]>'C'){
		qq=1;
	}
	
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if(qq==pp){
				cout<<"1";
				if(pp==1){
					cout<<"1";
				}
				else if(b[2]=='B'||d[2]=='B'){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
