#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,s1111="01",s2222="16";
bool ss(string a,string b){
	if(a.size()!=b.size()) return 0;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]) return 0;
	}
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(!ss(a,c)){
		cout<<"0000";
		return 0;
	} 
	cout<<"1";
	if(b[0]==d[0]&&b[1]==d[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C') cout<<"1";
	else if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'){
		cout<<"11";
		return 0;
	} 
	else{
		cout<<"00";
		return 0;
	}
	if(abs(b[2]-d[2])==1) cout<<"1";
	else cout<<"0";
	return 0;
} 
