#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,w1,w2;
int a=0,b=0,c=0;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		cout<<1;
		a=1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		a=0;
	}
	
	if(a==1){
		w1=s1[0]+s1[1];
		w2=s2[0]+s2[1];
		if(w1==w2){
			cout<<1;
			b=1;
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
			b=0;
		}
	}
	
	if(b==1){
		if(s1[2]=='A'){
			if(s2[2]=='B'||s2[2]=='C'){
				cout<<1;
				c=1;
			}else{
				cout<<0;
				cout<<0;
			}
		}
		if(s1[2]=='B'){
			if(s2[2]=='A'||s2[2]=='C'){
				cout<<1;
				c=1;
			}else{
				cout<<0;
				cout<<0;
			}
		}
		if(s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'){
				cout<<1;
				c=1;
			}else{
				cout<<0;
				cout<<0;
			}
		}
		if(s1[2]=='D'){
			if(s2[2]=='E'){
				cout<<1;
				c=1;
			}else{
				cout<<0;
				cout<<0;
			}
		}
		if(s1[2]=='E'){
			if(s2[2]=='D'){
				cout<<1;
				c=1;
			}else{
				cout<<0;
				cout<<0;
			}
		}
	}
	
	if(c==1){
		if(s1[2]=='A'){
			if(s2[2]=='B'){
				cout<<1;
			}else{
				cout<<0;
			}
		}
		if(s1[2]=='B'){
			if(s2[2]=='A'||s2[2]=='C'){
				cout<<1;
				c=1;
			}else{
				cout<<0;
			}
		}
		if(s1[2]=='C'){
			if(s2[2]=='B'){
				cout<<1;
				c=1;
			}else{
				cout<<0;
			}
		}
		if(s1[2]=='D'){
			if(s2[2]=='E'){
				cout<<1;
				c=1;
			}else{
				cout<<0;
			}
		}
		if(s1[2]=='E'){
			if(s2[2]=='D'){
				cout<<1;
				c=1;
			}else{
				cout<<0;
			}
		}
	}
	

	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
