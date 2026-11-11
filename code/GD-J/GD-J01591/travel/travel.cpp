#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b,c,d;
bool e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if((b[0]+b[1])!=(d[0]+d[1])){
		cout<<0;
		e=true;
	}
	else{
		cout<<1;
	}
	if(((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')))&&!e){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(((b[2]=='A'&&d[2]=='B')||(d[2]=='A'&&b[2]=='B')||(b[2]=='B'&&d[2]=='C')||(d[2]=='B'&&b[2]=='C')||(b[2]=='D'&&d[2]=='F')||(d[2]=='F'&&b[2]=='D'))&&!e){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
