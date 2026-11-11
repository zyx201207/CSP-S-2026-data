//GZ-J00166  遵义市第19中学 张铭泽
#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","v",stdin);
	freopen("travel.out","w",stdout);
	int sum=0;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) {
		sum=sum*10+1;
	} else {
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) {
		sum=sum*10+1;
	} else {
		cout<<"1000";
		return 0;
	}
	if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))) {
		sum=sum*10+1;
	} else {
		cout<<"1100";
		return 0;
	}
	if(b[2]=='A'&&d[2]=='B'){
		cout<<"1111";
	}else if(b[2]=='B'&&d[2]=='A'){
		cout<<"1111";
	}else if(b[2]=='B'&&d[2]=='C'){
		cout<<"1111";
	}else if(b[2]=='C'&&d[2]=='B'){
		cout<<"1111";
	}else if(b[2]=='D'&&d[2]=='F'){
		cout<<"1111";
	}else if(b[2]=='F'&&d[2]=='D'){
		cout<<"1111";
	}else {
		cout<<"1110";
	}
	return 0;
}
