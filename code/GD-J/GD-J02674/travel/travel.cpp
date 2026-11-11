#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>s1>>c1>>s2>>c2;
	bool a=1,b=1,c=1,d=1;
	for(int i=0;i<=s1.length();i++){
		if(s1[i]!=s2[i]){
			a=0;
		}
	}
	if(a){
		cout<<'1';
	}else{
		cout<<'0';
	}
	for(int i=0;i<c1.length()-1;i++){
		if(c1[i]!=c2[i]){
			a=0;
		}
	}
	if(a){
		cout<<'1';
	}else{
		cout<<'0';
	}
	for(int i=1;i<=3;i++){
		if(c1[2]=='A'||c1[2]=='B'||c1[2]=='C'){
			c=1;
		}else{
			c=0;
		}
		if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
			d=1;
		}else{
			d=0;
		}
	}
	if(c==d&&a){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(c==1&&d==1&&a){
		if(c1[2]-c2[2]==1||c1[2]-c2[2]==-1){
			cout<<'1';
		}else{
			cout<<'0';
		}
	}else if(c==0&&d==0&&a){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
} 
