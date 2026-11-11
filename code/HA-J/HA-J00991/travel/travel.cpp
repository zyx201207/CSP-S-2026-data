#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int n=s1[2]-'A'+1;
	int m=s2[2]-'A'+1;
	if(c1[0]==c2[0]&&c2[1]==c1[1]){
		cout<<"1";
	}
	else {
		cout<<"0000";
		return 0;	
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}
	else {
		cout<<"000";
		return 0;	
	}
	if(n<=3&&m<=3){
		if(abs(m-n)==2){
			cout<<"10";
			return 0;
		}
		if(abs(m-n)==1){
			cout<<"11";
			return 0;
		}	
	}
	else if(n>3&&m>3){
		cout<<"11";
		return 0;
	}
	else cout<<"00";
	return 0;
}
