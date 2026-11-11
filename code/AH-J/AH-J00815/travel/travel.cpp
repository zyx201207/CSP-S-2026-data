#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	string x="",y="";
	x=x+a1[0]+a1[1];
	y=y+b1[0]+b1[1];
	if(x!=y){
		cout<<"1000";
		return 0;
	}
	if(a1[2]>='A'&&a[2]<='C'&&b1[2]>='A'&&b1[2]<='C'){
		if(a1[2]=='A'&&b1[2]=='B'||a1[2]=='B'&&b1[2]=='C'||a1[2]=='B'&&b1[2]=='A'||a1[2]=='C'&&b1[2]=='B'){
			cout<<"1111";
			return 0;
		}else{
			cout<<"1110";
			return 0;
		}
	}else if(a1[2]=='D'&&b1[2]=='F'||a1[2]=='F'&&b1[2]=='D'){
		cout<<"1111";
		return 0;
	}else{
		cout<<"1100";
		return 0;
	}
	return 0;
}
