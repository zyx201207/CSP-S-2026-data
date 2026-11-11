#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3){
		cout<<"0000";
		return 0;
	}else if(s2.substr(0,2)!=s4.substr(0,2)){
		cout<<"1000";
	}else if((int(s2[2])>=68&&int(s4[2])<=67)||(int(s2[2])<=67&&int(s4[2])>=68)){
		cout<<"1100";
	}else if(int(s2[2])>=68&&int(s4[2])>=68){
		cout<<"1111";
	}else if(abs(int(s2[2]))-int(s4[2])==2){
		cout<<"1110";
	}
	else{
		cout<<"1111";
	}
	return 0;
}
