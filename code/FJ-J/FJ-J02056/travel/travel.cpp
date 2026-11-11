#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s="ABCDF";
int a[5]={1,2,3,5,6};
int sz(string s){
	return 10*(int(s[0]-'0'))+(int(s[1]-'0'));
}
int en(char s0){
	for(int i=0;i<5;i++){
		if(s0==s[i]) return a[i];
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(sz(c1)!=sz(c2)){
		cout<<"0000";return 0;
	}
	else if(sz(s1)!=sz(s2)){
		cout<<"1000";return 0;
	}
	else if(abs(en(s1[2])-en(s2[2]))==1){
		cout<<"1111";
	}
	else if(en(s1[2])<4&&en(s2[2])<4){
		cout<<"1110";
		return 0;
	}
	else cout<<"1100";
	return 0;
}
