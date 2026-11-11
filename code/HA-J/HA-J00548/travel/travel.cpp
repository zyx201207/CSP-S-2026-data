#include<bits/stdc++.h>
using namespace std;
int i,j,n,m,b,v,o,f;
string s,k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	o=s.size();
	f=k.size();
	cin>>n>>s>>b>>k;
	if(n==b){
		cout<<"1";
	
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s[1]=k[1]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(s[2]=k[2]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(s[o]=='D'&&k[f]=='D'){
		cout<<"0";
		return 0;
	}
	else if(s[o]-'0'+1==k[f]-'0'&&s[o]-'0'-1==k[f]-'0'){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
