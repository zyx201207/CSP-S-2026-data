#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2,t="ABCDF";

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		printf("0000");
	}
	else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		printf("1000");
	}
	else if(!(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D')){
		printf("1100");
	}
	else if(abs(int(t.find(s1[2])-t.find(s2[2])))!=1){
		printf("1110");
	}
	else
		printf("1111");
	return 0;
}