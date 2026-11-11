#include<bits/stdc++.h>
typedf long long ll;
using namespace std;
string a,b,c,d;
bool side(char c){
	if(c=="A"||c=="B"||c=="C"){
		return true;
		}
		return false;
	}
int main(){
    freopen("travel.i",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c){
	     cout<<"0000";
	     return 0;
	}
	if(b[0]!=d[0]||b[1!=d[1]){
		cout<<"1000";
return 0;
}
if(side(b[2])!=side(d[2])){
	cout<<"1100";
	return 0;
}
if((b[2]=='D'&&d[2]!='F')||(b[2]=='F'&&d[2]!='D')
||(b[2]=='A'&&d[2]!='B')||(b[2]=='c'&&d[2]!='B')||(
b[2]=='B'&&d[2]!='A'&&d[2]!='C')){
	cout<<"1110";
	return 0;
}
cout<<"1111";
return 0;
}

