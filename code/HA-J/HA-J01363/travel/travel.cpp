#include<bits/stdc++.h>
using namespace std;
long long a,c;
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(b[2]=='D'||b[2]=='E'){
		if('D'!=d[2]||'E'!=d[2]){
			cout<<"00";
			return 0;
		}
	}
	else{
		if('D'==d[2]||'E'==d[2]){
			cout<<"00";
			return 0;
		}
	}
	cout<<1;
	if('A'==d[2]&&'C'==b[2]||'C'==d[2]&&'A'==b[2]){
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
}
