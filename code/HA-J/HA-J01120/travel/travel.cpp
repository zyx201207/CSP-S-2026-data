#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	char a=s1[2],b=s2[2];
	
	int a1=(s1[0]-'0')*10+s1[1]-'0';
	int b1=(s2[0]-'0')*10+s2[1]-'0';
	int flag=1;
	
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
		flag=0;
	} 
	
	if(a1==b1&&flag==1){
		cout<<1;
	}
	else{
		cout<<0;
		flag=0;
	}
	
	
	
	if(flag==1){
		if(a=='D'||a=='C'){
			if(b=='D'||b=='C'&&a!=b){
				flag=0;
			}	
		}
		
		else if(a=='F'||a=='D'){
			if(b=='F'||b=='D'&&a!=b){
				flag=1;
			}
		}
		else if(a=='A'||a=='B'||a=='C'){
			if(b=='A'||b=='B'||b=='C'&&a!=b){
				flag=1;
			}
		}
		else{
			flag=0;
		}
		
		if(flag==1){
			cout<<1;
		}
		else{
			cout<<0;
			flag=0;
		}
	}
	else{
		cout<<0;
		flag=0;
	}
	
	if(flag==0){
		cout<<0;
	}
	else if(int(a-b)==1||int(a-b)==-1&&flag==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
		
	return 0;
}
