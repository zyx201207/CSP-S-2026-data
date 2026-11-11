#include<bits/stdc++.h>
using namespace std;
bool x(string a,string b){
	if(a.size()!=b.size()) return false;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]) return false;
	}
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(!x(a1,b1)){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(!x(a2.substr(0,2),b2.substr(0,2))){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(((a2[2]=='E'||a2[2]=='D')&&(b2[2]=='E'||b2[2]=='D'))||(a2[2]!='E'&&a2[2]!='D'&&b2[2]!='E'&&b2[2]!='D')){
		cout<<1;
		if(a2[2]=='B'||b2[2]=='B'||a2[2]=='D'||b2[2]=='D'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<"00";
	}
	return 0;
}
