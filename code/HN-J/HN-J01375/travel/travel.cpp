#include<bits/stdc++.h> 
using namespace std;
string a,b,c,d;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>b>>c>>d;
char g,h;
g=b[2],h=d[2];

if(a==c){
	cout<<"1";
	if(b[0]==d[0] && b[1]==d[1]){
		cout<<"1";
		if(g=='A' || g=='B' || g=='C' && h=='B' ||h=='A' || h=='C'){
			cout<<"1";
			if(g=='B'){
				cout<"1";
			}else if(h=='B'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else if(g=='D' || g=='F' && g=='D'|| g=='F'){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}else{
		cout<<"000";
	}
}else{
	cout<<"0000";
}
return 0;
}
