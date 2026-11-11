#include<bits/stdc++.h>
using namespace std;
char c1[2],s1[3],c2[2],s2[3];
bool flag=true;
int main(){
	freopen("travel.in",r,stdin);
	freopen("travel.out",w,stdout);
	for(int i=0;i<=1;i++){
		cin>>c1[i];
	}
	for(int i=0;i<=2;i++){
		cin>>s1[i];
	}
	for(int i=0;i<=1;i++){
		cin>>c2[i];
	}
	for(int i=0;i<=2;i++){
		cin>>s2[i];
	}
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
	}
	else{
		cout<<0;
		flag=false;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag){
		cout<<1;
	}
	else{
		cout<<0;
		flag=false;
	}
	if(((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))&&flag){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(abs(int(s1[2]-s2[2]))==1&&flag){
		if(s1[2]=='C'&&s2[2]=='D'){
			cout<<0;
		}
		else if(s2[2]=='C'&&s1[2]=='D'){
			cout<<0;
		}
		else{
			cout<<1;
		}
	}
	else if(((s2[2]=='D'&&s1[2]=='F')||(s2[2]=='F'&&s1[2]=='D'))&&flag){
		
	}
	else{
		cout<<0;
	}
	return 0;
} 
