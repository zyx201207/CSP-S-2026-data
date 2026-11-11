//GZ-J00018 金沙县第三中学  孟彧臣 
#include<bits/stdc++.h>
using namespace std;
#define long long
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long c1,c2;
	string s1,s2;
	int e=0,f=0,c=0;
	cin>>c1>>s1>>c2>>s2;
	int a,x;
	for(int i=0;i<2;i++){
		a=a+s1[i];
	}
	s1=s1[2];
	for(int i=0;i<2;i++){
		x=x+s2[i];
	}
	s2=s2[2];
	if(c1==c2){
		cout<<"1";
		e=1;
	}
	else{
		cout<<"0";
	}
	if(e==1){
		if(a==x){
			cout<<"1";
			f=1;
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"0";
	}
	if(f==1){
		if(((s1=="A"|| s1=="B" || s1=="C") && (s2=="A"|| s2=="B" || s2=="C")) || ((s1=="F"||s1=="D") && (s2=="D"|| s2=="F"))){
			cout<<"1";
			c=1;
		}
	}
	else{
		cout<<"0";
	}
	if(c==1){
		if((s1=="A" && s2=="B") || (s1=="B" && s2=="C")|| (s1=="C" && s2=="B")|| (s1=="D" && s2=="F")|| (s1=="F" && s2=="D")){
			cout<<"1";
		}
	}
	else{
		cout<<"0";
	}
	return 0;
} 
