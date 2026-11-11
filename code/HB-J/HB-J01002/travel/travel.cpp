#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int f1,f2,f3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0] and c1[1]==c2[1]){
		cout<<1;
		f1=1;
	}else{
		cout<<0;
	}
	
	if(f1 and s1[0]==s2[0] and s1[1]==s2[1]){
		cout<<1;
		f2=1;
	}else{
		cout<<0;
	}
	
	if(f2){
		if(s1[2]=='D' and s2[2]=='F'){
			cout<<1;
			f3=1;
		}else if(s1[2]=='F' and s2[2]=='D'){
			cout<<1;
			f3=1;
		}
		else if(s1[2]=='D' or s1[2]=='F' or s2[2]=='F' or s2[2]=='D'){
			cout<<0;
		}else{
			cout<<1;
			f3=2;
		}
	}else{
		cout<<0;
	}
	
	if(f3==1){
		cout<<1;
	}else if(f3==2){
		if(s1[2]=='B' or s2[2]=='B'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
