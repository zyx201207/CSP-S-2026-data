#include<bits/stdc++.h>
using namespace std;
int a,a1,b,b1;
char a2,b2;
bool pd(char a,char b){
	if(a=='A'||a=='B'||a=='C'){
		if(b=='A'||b=='B'||b=='c'){
			return true;
		}
	}
	if(a=='D'||a=='F'){
		if(b=='D'||b=='F'){
			return true;
		}
	}
	return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>a2>>b>>b1>>b2;
	if(a==b){
		cout<<1;
	} else{
		cout<<0;
	}
	if(a==b){
		if(a1==b1){
			cout<<1;
		}else{
			cout<<0;
		}
	} else{
		cout<<0;
	}
	if(a==b){
		if(a1==b1){
			if(pd(a2,b2)){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	} else{
		cout<<0;
	}
	if(a==b&&a1==b1&&pd(a2,b2)){
		if(a2-b2==-1||a2-b2==1){
			cout<<1;	
		}else{
			cout<<0;
		}	
	}else{
		cout<<0;
	} 
	return 0;
} 
