#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool flag1=1,flag2=1;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i])flag1=0;
	} 
	if(flag1)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i])flag2=0;
	} 
	if(flag2)cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	
	int a='C'-s1[2];
	int b='C'-s2[2];
	if(a>=0&&b>=0){
		cout<<1;
		if(a-b==1||b-a==1)cout<<1;
		else cout<<0;
	}
	else if(b<0&&a<0){
		cout<<1<<1;
	}
	else cout<<0<<0;
}

