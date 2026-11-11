#include<bits/stdc++.h>
using namespace std;
string c1,s1,s2,c2;
bool check(string q,string p){
	for(int i=0;i<=1;i++){
		if(q[i]!=p[i]) return false;
	}
	return true;
}
bool check2(char r,char u){
	if((r>='A'&&r<='C')&&(u>='A'&&u<='C')) return true;
	if((r>='D'&&r<='F')&&(u>='D'&&u<='F')) return true;
	return false; 
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(check(s1,s2)) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(check2(s1[2],s2[2])) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])!=1) cout<<"0";
	else cout<<"1";
	return 0;
} 
