#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int a,b;
	int x=0;
	int y=0;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<"1";
		x=1;
	}else{
		x=0;
		cout<<"0";
	}
	if(10*c[0]+c[1]==10*d[0]+d[1]&&x==1){
		cout<<'1';
	}else{
		cout<<'0';
		x=0;
	}
	if((c[2]=='A'||c[2]=='B'||c[2]=='C'&&d[2]=='A'||d[2]=='B'||d[2]=='C')||(c[2]=='D'||c[2]=='F'&&d[2]=='D'||d[2]=='F')){
		if(x==1){
			cout<<"1";
			y=1;
		}
	}
	if(y==0){
		cout<<'0';
	}
	if((c[2]=='A'&&d[2]=='B')||(d[2]=='A'&&c[2]=='B')||(c[2]=='B'&&d[2]=='C')||(c[2]=='C'&&d[2]=='B')||(c[2]=='D'&&d[2]=='F')||(c[2]=='F'&&d[2]=='D')){
		if(x==1){
			cout<<'1';
			return 0;
		}
	}
	cout<<'0';
	return 0;
} 
