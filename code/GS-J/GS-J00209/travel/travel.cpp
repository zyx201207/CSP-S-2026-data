#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string b,d;
	int a,c;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}cout<<1;
	if(int(b[0])*10==int(d[0])*10){
		if(int(b[1])*10==int(d[1])*10){
			cout<<1;
		}else {
			cout<<"000";
			return 0;
		}
	}if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}else if(b[2]=='F'||b[2]=='D'){
		if(d[2]=='F'||d[2]=='D'){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}if(b[2]=='B'||d[2]=='B'){
		cout<<1;
	}
	return 0;
}
