#include<bits/stdc++.h>
using namespace std;
string a,b,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a!=b){
		printf("0000");
		return 0;
	}
	else{
		printf("1");
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if(s1[2]>s2[2])
			swap(s1,s2);
		printf("1");
	}
	else {
		printf("000");
		return 0;
	}
	if(s2[2]<='C'||s1[2]>='D'){
		printf("1");
	}
	else {
		printf("00");
		return 0;
	}
	if(s1[2]==s2[2]-1){
		printf("1");
	}
	else {
		printf("0");
		return 0;
	}
	return 0;
}
