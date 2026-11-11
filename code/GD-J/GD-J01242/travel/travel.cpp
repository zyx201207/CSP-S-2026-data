#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else cout<<"0";
	if(s1[0]==s2[0] and s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s1[2]=='F' or s1[2]=='D'){
		if(s2[2]=='F' or s2[2]=='D'){
			cout<<"1";
		}
	}
	if(s1[2]=='A' or s1[2]=='B' or s1[2]=='C'){
		if(s2[2]=='A' or s2[2]=='B' or s2[2]=='C'){
			cout<<"1";
		}
	}else{
		cout<<"0";
	}
	if(s1[2]-s2[2]==1){
		cout<<"1";
	}
	if(s2[2]-s1[2]==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
