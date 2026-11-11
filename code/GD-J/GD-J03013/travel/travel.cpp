#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int g;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		g=1;
	}
	else {
		cout<<0;
		g=0;
	}
	string zuo1,zuo2;
	zuo1+=s1[0]+s1[1];
	zuo2+=s2[0]+s2[1];
	int f;
	if(g==0){
		cout<<0<<0<<0;
		return 0;
	}
	if(zuo1==zuo2){
		cout<<1;
		f=1;
	}
	else{
		cout<<0;
		f=0;
	}
	if(f){
		if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
			cout<<1;
		
		}
		else cout<<0;
		int a1=s1[2]-65,a2=s2[2]-65;
	
	
		if(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'){
			cout<<0;
		}else if(abs(a1-a2)==1||(s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F')){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0<<0;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
