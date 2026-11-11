#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool gd(char a,char b){
	if(a<b){
		swap(a,b);
	}
	if(a=='F'&&b!='D'){
		return 0;
	}
	if(a=='D'){
		return 0;
	}
	return 1;
}
bool tb(char a,char b){
	if(a<b){
		swap(a,b);
	}
	if(a=='F'&&b!='D'){
		return 0;
	}
	if(a=='D'){
		return 0;
	}
	if(a=='C'&&b!='B'){
		return 0;
	}
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
	}
	else if(!gd(s1[2],s2[2])){
		cout<<"1100";
	}
	else if(!tb(s1[2],s2[2])){
		cout<<"1110";
	}
	else{
		cout<<"1111";
	}
	return 0;
}
