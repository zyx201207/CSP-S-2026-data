#include<bits/stdc++.h>
using namespace std;
string x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool flag=0;
	for(int i=0; i<2; i++){
		if(a[i]==c[i])flag=1;
		else{
			flag=0;
			break;
		}
	}
	if(flag)x+='1';
	else{
		x+='0';
		x+='0';
		x+='0';
		x+='0';
		cout<<x;
		return 0;
	}
	flag=0;
    for(int i=0; i<2; i++){
		if(b[i]==d[i])flag=1;
		else{
			flag=0;
			break;
		}
	}
	if(flag)x+='1';
	else{
		x+='0';
		x+='0';
		x+='0';
		cout<<x;
		return 0;
	}
	flag=0;
	if(b[2]=='A'&&d[2]=='B'||b[2]=='A'&&d[2]=='C'||b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'){
		x+='1';
	}
	else if(b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
		x+='1';
		x+='1';
		cout<<x;
		return 0;
	}
	else{
		x+='0';
	}
	if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'){
		x+='1';
	}
	else{
		x+='0';
	}
	cout<<x;
	return 0;
} 
