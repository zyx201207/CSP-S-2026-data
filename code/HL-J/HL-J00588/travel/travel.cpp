#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int ac=(a[0]-'0')*10+(a[1]-'0');
	int bc=(c[0]-'0')*10+(c[1]-'0');
	int ap=(b[0]-'0')*10+(b[1]-'0');
	int bp=(d[0]-'0')*10+(d[1]-'0');
	char as=b[2],bs=d[2];
	if(as=='D')as='E';
	if(bs=='D')bs='E';
	bool s=0,ne=0;
	if(!(ac==bc)){
		cout<<"0000";
		return 0;
	}
	if(!(ap==bp)){
		cout<<"1000";
		return 0;
	}
	if(as==bs-1){
		s=1;
		ne=1;
	}
	if(as==bs+1){
		s=1;
		ne=1;
	}
	if(as=='A'&&bs=='C'){
		s=1;
	}
	if(as=='C'&&bs=='A'){
		s=1;
	}
	if(!s){
		cout<<"1100";
		return 0;
	}
	if(!ne){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
