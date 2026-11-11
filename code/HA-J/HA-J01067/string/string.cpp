#include<bits/stdc++.h>
using namespace std;
long long s;
int a[100000005];
string sw[100000005];/*
bool okk(string n,string g){
	bool l;
	p=false;
	for(int i=n.size();i>=1;i++){
		if(g[u]=n[i]){
			l=true;
		}
		else l=false;
	}
	return l;
}*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s;
	if(s==1) cout<<"0";
	else{
	bool c=true;
	for(int i=1;i<=s;i++){
		cin>>a[i]>>sw[i];
	}
	
	for(int i=1;i<s;i++){
		if(s==2&&sw[1]!=sw[2]){
			cout<<min(a[1],a[2]);
		}
		if(sw[i]==sw[i+1]){
			c=false;
		}
		else c=true;
	}
	if(!c){
		cout<<"0";
	}
}
	return 0;
}
