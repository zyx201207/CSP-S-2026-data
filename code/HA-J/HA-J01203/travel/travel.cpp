#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ans = "";
	int kg = 1;
	if(c1 == c2){
		ans = ans+"1";
	}else{
		ans = ans+"0";
		kg = 0;
	}
	
	if(s1[0] == s2[0] && s1[1] == s2[1] && kg==1){
		ans = ans+"1";
	}else{
		ans = ans+"0";
		kg = 0;
	}
	
	if(s1[2]>='D' && s2[2]>='D' && kg==1){
		ans = ans+"11";
	}else if(s1[2]<'D' && s2[2]<'D' && kg==1){
		ans = ans+"1";
		if(s1[2]=='B' || s2[2]=='B'){
			ans = ans+"1";
		}else{
			ans = ans+"0";
			kg = 0;
		}}
	else{
		ans = ans+"00";
		kg = 0;
	}
	cout<<ans;
	
	
	return 0;
}
