//GZ-J00071 张世铠 贵阳市白云区华师一学校 
#include<bits/stdc++.h>
using namespace std;
bool check(char c,char d){
	if(c>='A' && c<='C' && d>='A' && d<='C'){
		return 1;
	}
	else if(c>='D' && c<='E' && d>='D' && d<='E'){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else if(s1[0]+s1[1]!=s2[0]+s2[1]){
		cout<<"1000";
	}
	else if(!check(s1[2],s2[2])){
		cout<<"1100";
	}
	else if(abs(s1[2]-s2[2])!=1){
		cout<<"1110";
	}
	else{
		cout<<"1111"; 
	}
	
	return 0;
}
