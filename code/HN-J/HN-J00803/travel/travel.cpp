#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	long long a,c;
	string b,d;
	bool e[4]={0,1,1,0};
	cin>>a>>b>>c>>d;
	if(a==c){
		e[1]=true;
	}
	else e[1]=false;
	if('b'-'d'==1||'d'-'b'==1){
		e[4]=true;
	}
	else e[4]=false;
	for(int i=1;i<=4;i++){
		cout<<e[i];
	}
	return 0;
}
