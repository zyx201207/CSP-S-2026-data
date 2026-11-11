#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(s1[2]<='C'&&s2[2]<='C'){
		if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
			cout<<"11";
		}
		else{
			cout<<"10";
		}
	}
	else if(s1[2]>='D'&&s2[2]>='D'){
		if(s1[2]+2==s2[2]||s1[2]-2==s2[2]){
			cout<<"11";
		}else{
			cout<<"10";
		}
	}else{
		cout<<"00";
		return 0;
	}
	return 0;
}
