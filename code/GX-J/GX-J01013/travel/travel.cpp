#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a=0,b=0;
	if(s1[2]=='A'){
		a=1;
	}
	if(s1[2]=='B'){
		a=2;
	}
	if(s1[2]=='C'){
		a=3;
	}
	if(s1[2]=='D'){
		a=6;
	}
	if(s1[2]=='F'){
		a=7;
	}
	if(s2[2]=='A'){
		b=1;
	}
	if(s2[2]=='B'){
		b=2;
	}
	if(s2[2]=='C'){
		b=3;
	}
	if(s2[2]=='D'){
		b=6;
	}
	if(s2[2]=='F'){
		b=7;
	}
	int flag=0;
	if(c1==c2){
		cout<<"1";
		flag++;
	}else{
		cout<<"0";
	}
	if(s1[0]!=s2[0]){
		cout<<"0";	
	}
	else{
		if(s1[1]==s2[1]&&c1==c2){
			cout<<"1";
			flag++;
		}
		else{
			cout<<"0";
		}
		
	}
	if(s1[1]==s2[1]&&c1==c2&&s1[0]==s2[0]){
		if(abs(a-b)<=2){
			cout<<"1";
			flag++;
		}else{
			cout<<"0";
		}
	}
	else{
		cout<<"0";
	}
	if(flag==3){
		int h=abs(a-b);
		if(h==1){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	
	return 0;
}
