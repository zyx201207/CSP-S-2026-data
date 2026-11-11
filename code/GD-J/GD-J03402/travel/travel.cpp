#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r".stdin);
	freopen("travel.out","w",stdout);
	long long a,b,e=0;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b){
		e+=1;
	}else {
	cout<<"0000";
	return 0;
	}
	if(c[0]*10+c[1]==d[0]*10+d[1]){
		e*=10;
		e+=1;
	}else {
		cout<<"1000";
		return 0;
	}
	if((c[2]<='C'&&d[2]<='C')||(c[2]>='D'&&d[2]>='D')){
		e*=10;
		e+1;
	}else {
		cout<<"1100";
		return 0;
	}
	if(c[2]-d[2]==-1||c[2]-d[2]==1||(c[2]=='D'&&d[2]=='F')||(c[2]=='F'&&d[2]=='D')){
		cout<<"1111";
	}else cout<<"1110";
	return 0;
}
