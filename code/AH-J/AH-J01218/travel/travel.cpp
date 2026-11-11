#include<bits/stdc++.h>
using namespace std; 
int a[7]={1,1,1,2,0,2};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1n,s1n,c2n,s2n;
	cin>>c1n>>s1n>>c2n>>s2n;
	if(c1n[0]!=c2n[0]||c1n[1]!=c2n[1]){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
	}
	if(s1n[0]!=s2n[0]||s1n[1]!=s2n[1]){
		cout<<"000";
		return 0;
	}
	else{
		cout<<"1";
	}
	if(a[s1n[2]-65]!=a[s2n[2]-65]){
		cout<<"00";
		return 0;
	}
	else{
		cout<<"1";
	}
	if(abs(s1n[2]-s2n[2])!=1){
		cout<<"0";
	}
	else{
		cout<<"1";
	}
	return 0;
}
