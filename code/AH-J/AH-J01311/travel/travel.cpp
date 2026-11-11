#include <iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b;
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	if(a==b) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(a1[0]==b1[0]&&a1[1]==b1[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(((a1[2]=='A'||a1[2]=='B'||a1[2]=='C')&&(b1[2]=='A'||b1[2]=='B'||b1[2]=='C'))||((a1[2]=='D'||a1[2]=='F')&&(b1[2]=='D'||b1[2]=='F'))) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((a1[2]=='D'&&b1[2]=='F')||(b1[2]=='D'&&a1[2]=='F')){
		cout<<1;
		return 0;
	}
	if((a1[2]+1==b1[2]||b1[2]+1==a1[2])&&(a1[2]!='C'&&b1[2]!='C')) cout<<1;
	else cout<<"0";
	return 0;
}
