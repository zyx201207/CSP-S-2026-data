#include<bits/stdc++.h>
using namespace std;
string s;
int pf(int t){
	if(t==0) return 10;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2,s3,s4;
	c1=c2=s1=s2=s3=s4=0;
	for(int i=1;i<=4;i++){
		cin>>s;
		for(int j=0;j<=1;j++){
			if(i==1) c1=c1+(s[j]-48)*pf(j);
			if(i==2) s1=s1+(s[j]-48)*pf(j);
			if(i==3) c2=c2+(s[j]-48)*pf(j);
			if(i==4) s2=s2+(s[j]-48)*pf(j);
		}
		if(i%2==0){
			if(i==2){
				if(s[2]=='A') s3=1;
				if(s[2]=='B') s3=2;
				if(s[2]=='C') s3=3;
				if(s[2]=='D') s3=5;
				if(s[2]=='F') s3=6;
			}
			if(i==4){
				if(s[2]=='A') s4=1;
				if(s[2]=='B') s4=2;
				if(s[2]=='C') s4=3;
				if(s[2]=='D') s4=5;
				if(s[2]=='F') s4=6;
			}
		}
	}
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(s1!=s2){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if((s3<=4&&s4>=4)||(s3>=4&&s4<=4)){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(max(s3,s4)-min(s3,s4)==1){
		cout<<"1";
		return 0;
	}
	cout<<"0";
	return 0;
}
