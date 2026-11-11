#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[4],s2[4];
	cin>>c1>>s1[1]>>s1[2]>>s1[3]>>c2>>s2[1]>>s2[2]>>s2[3];
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[1]==s2[1]&&s1[2]==s2[2]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(s1[3]-'C'>0&&s2[3]-'C'>0){
		cout<<"1";
	}else if(s1[3]-'C'<=0&&s2[3]-'C'<=0){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(s1[3]-s2[3]==1){
		cout<<"1";
	}else if(s2[3]-s1[3]==1){
		cout<<"1";
	}else if(s1[3]=='D'&&s2[3]=='F'){
		cout<<"1";
	}else if(s1[3]=='F'&&s2[3]=='D'){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
