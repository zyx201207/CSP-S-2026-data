#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	string s,t;
	cin>>a>>s>>b>>t;
	if(a==b) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s[0]==t[0] && s[1]==t[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((s[2]>='A' && s[2]<='C' && t[2]>='A' && t[2]<='C') || (s[2]>='D' && s[2]<='F' && t[2]>='D' && t[2]<='F')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(max((int)s[2],(int)t[2])==min((int)s[2],(int)t[2])+1){
		cout<<1;
	}
	else cout<<0;
	return 0;
}

