#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool nsame1(){
	if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='D'||d[2]=='F')){
		return 1;
	}
	if((d[2]=='A'||d[2]=='B'||d[2]=='C')&&(b[2]=='D'||b[2]=='F')){
		return 1;
	}
	return 0;
}
bool nsame2(){
	if(b[2]=='A'&&d[2]=='C'){
		return 1;
	}
	if(b[2]=='C'&&d[2]=='A'){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]!=c[0]||a[1]!=c[1]){
		cout<<"0000";
		return 0;
	}
	if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"1000";
		return 0;
	}
	if(nsame1()){
		cout<<"1100";
		return 0;
	}
	if(nsame2()){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
    return 0;
}
