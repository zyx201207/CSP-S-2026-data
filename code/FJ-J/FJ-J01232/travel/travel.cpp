#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,anss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!="01"&&c1!="16"&&c2!="01"&&c2!="16"){
		if(c1==c2){
			anss[1]='1';
		}
		else{
			anss[1]='0';
		}
		if(s1[1]==s2[1]){
			anss[2]='1';
		}
		else{
			anss[2]='0';
		}
		if(s1[1]==s2[1]&&(s1[2]<='c'&&s2[2]<='c')||(s1[2]>='c'&&s2[2]>='c')){
			anss[3]='1';
		}
		else{
			anss[3]='0';
		}
		if((s1[1]==s2[1])&&(s1[2]-s2[2]==1||s2[2]-s1[2]==1)){
			anss[4]='1';
		}
		else{
			anss[4]='0';
		}
	}
	for(int i=1;i<=4;i++){
		cout<<anss[i];
	}
	return 0;
}
