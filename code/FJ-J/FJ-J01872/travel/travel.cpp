#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int f1(string a,string b){
	for(int i=0;i<2;i++){
		if(a[i]!=b[i]){
			return 0;
		}
	}
	return 1;
}
int f2(string a,string b){
	if('C'>=a[2]&&'C'>=b[2]){
		return 1;
	}
	if(a[2]>='D'&&b[2]>='D'){
		return 1;
	}
	return 0;
}
int f3(char a,char b){
	if(a=='A'){
		if(b=='B'){
			return 1;
		}
	}
	else if(a=='B'){
		if(b=='A'||b=='C'){
			return 1;
		}
	}
	else if(a=='C'){
		if(b=='B')
		return 1;
	}
	else if(a=='D'&&b=='F'){
		return 1;
	}
	else if(a=='F'&&b=='D'){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(f1(c1,c2)==0){
		cout<<"0000";
		return 0;
	}
	if(f1(s1,s2)==0){
		cout<<"1000";
		return 0;
	}
	if(f2(s1,s2)==0){
		cout<<"1100";
		return 0;
	}
	if(f3(s1[2],s2[2])==0){
		cout<<"1110";
	}
	else{
		cout<<"1111";
	}
	return 0;
}
