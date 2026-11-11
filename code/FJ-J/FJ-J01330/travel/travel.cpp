#include<bits/stdc++.h>
using namespace std;
char l[]="ABC";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	vector<string>v(10);
	for(int i=1;i<=4;i++){
		cin>>v[i];
	}
	int a=0,b=0,c=0,d=0;
	if(v[1]!=v[3]){cout<<"0000";return 0;}
	else{a=1;}
	if(v[2][0]==v[4][0]&&v[2][1]==v[4][1]){
		b=1;
	}else{
		cout<<a<<"000";
		return 0;
	}
	bool flag=false;
	
	for(int i=0;i<3;i++){
		if(v[2][2]==l[i]&&v[4][2]==l[i]){
			c=1;flag=true;break;
		}else if((v[2][2]=='D'&&v[4][2]=='F')||(v[2][2]=='F'&&v[4][2]=='D')){
			c=1;flag=true;break;
		}
		else{
			c=0;
			flag=false;
		}
	}
	if(!flag){
		cout<<"1100";
		return 0;
	}
	if((v[2][2]=='A'&&v[4][2]=='C')||(v[4][2]=='A'&&v[2][2]=='C')){
		d=0;
		cout<<a<<b<<c<<d;
		return 0;
	}else{
		d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
