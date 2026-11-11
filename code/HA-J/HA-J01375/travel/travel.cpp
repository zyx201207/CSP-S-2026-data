#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,d,f,g;
	cin>>s>>d>>f>>g;
	int as,ad,af,ag,bs,bd;
	as=s[1]-'0'+(s[0]-'0')*10;
	af=f[1]-'0'+(f[0]-'0')*10;
	ad=d[1]-'0'+(d[0]-'0')*10;
	ag=g[1]-'0'+(g[0]-'0')*10;
	bs=d[2]-'A'+1;
	bd=g[2]-'A'+1;
	if(as==af){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(as==af and ad==ag){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(as==af and ad==ag and ((bs<=3 and bd<=3) or (bs>=4 and bd>=4))){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(as==af and ad==ag and ((bs<=3 and bd<=3) or (bs>=4 and bd>=4)) and ((as+1==af or as-1==af) or (bs+1==bd or bs-1==bd))){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
