#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1.substr(0,2)==s2.substr(0,2)){
		cout<<1;
	}else {
		cout<<"000";return 0;
	}
	if('A'<=s1[2]&&s1[2]<='C'){
		if('A'<=s2[2]&&s2[2]<='C'){
			cout<<1;
			if(abs(s1[2]-s2[2])==1){
				cout<<1;
			}else cout<<0;
		}else{
			cout<<"00";return 0;
		}
	}else if('D'<=s1[2]&&s1[2]<='F'){
		if('D'<=s2[2]&&s2[2]<='F'){
			cout<<1;
			if(s1[2]!=s2[2]){
				cout<<1;
			}else cout<<0;
		}else{
			cout<<"00";return 0;
		}
	}
	return 0;
} 

