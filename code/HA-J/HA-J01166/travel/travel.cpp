#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int fl_chexiang=0;
	if(a==c){
		cout<<1;	
		fl_chexiang=1;
	}else{
		cout<<0;
	}
	int fl_yipai=0;
	int b1=(b[0]-'0')*10+b[1]-'0';
	int d1=(d[0]-'0')*10+d[1]-'0';
	if(b1==d1&&fl_chexiang==1){
		cout<<1;
		fl_yipai=1;
	}else{
		cout<<0;
	}
	int fl=0;
	if(fl_yipai==1){
		if(b[2]=='D'&&d[2]=='F'|| b[2]=='F'&&d[2]=='D' || b[2]=='A'&&d[2]=='B' || b[2]=='A'&&d[2]=='C' || b[2]=='B'&&d[2]=='A' || b[2]=='B'&&d[2]=='C' || b[2]=='C'&&d[2]=='A' || b[2]=='C'&&d[2]=='B'){
			cout<<1;                      
			fl=1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(fl==1){
		if(abs(b[2]-d[2])==1 || b[2]=='D'&&d[2]=='F' || b[2]=='F'&&d[2]=='D'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	
	return 0;
}
