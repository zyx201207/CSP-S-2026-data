#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int bs1,bs2;
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		bs1=1;
	}else{
		bs1=2;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		bs2=1;
	}else{
		bs2=2;
	}
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}else if(bs1!=bs2){
		cout<<"1100";
		return 0;
	}else if(s1[2]!=s2[2]+1&&s1[2]!=s2[2]-1){
		cout<<"1110";
		return 0;
	}else{
		cout<<"1111";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
