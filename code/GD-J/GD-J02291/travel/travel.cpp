#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,s1,s2;
	cin >>a1>>a2>>s1>>s2;
	if (a1=="01" || a1=="16" || a1!=s1){
		cout <<"0000";
		return 0;
	}else if(a2[0]+a2[1]!=s2[0]+s2[1]){
		cout <<"1000";
		return 0;
	}else if(a2[2]>='A' && a2[2]<='C' && s2[2]>='A' && s2[2]<='C' || a2[2]>='D' && a2[2]<='F' && s2[2]>='D' && s2[2]<='F'){
		if (a2[2]+1==s2[2] || a2[2]==s2[2]+1){
			cout <<"1111";
			return 0;
		}else{
			cout <<"1110";
			return 0;
		}
	}else{
		cout <<"1100";
		return 0;
	}
	return 0;
} 
