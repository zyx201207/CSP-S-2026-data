#include<iostream>
#include<cstring>
using namespace std;
string a,b,c,d;
int f,ff,fff;
signed main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		fff = 1;
		cout<<"1";
	} 
	else{
		fff = 0;
		cout<<"0";
	}
	if(fff){
		f = 1;
		for(int i =0;i<=1;i++){
			if(b[i]!=d[i])f = 0;
		}
		cout<<f;
	}
	else{
		f = 0;
		cout<<0;
	}
	if(f){
		if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
			if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
				ff = 1;
				cout<<1;
			} 
			else{
				ff = 0;
				cout<<0;
			}
		}
		else{
			if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
				ff = 0;
				cout<<0;
			}
			else{
				ff = 1;
				cout<<1;
			}
		}
	}
	else{
		ff = 0;
		cout<<0;
	}
	if(ff){
		if(b[2]=='A'){
			if(d[2]=='B')cout<<1;
			else cout<<0;
		}
		if(b[2]=='B'){
			if(d[2]=='A'||d[2]=='C')cout<<1;
			else cout<<0;
		}
		if(b[2]=='C'){
			if(d[2]=='B')cout<<1;
			else cout<<0; 
		}
		if(b[2]=='D'){
			if(d[2]=='E')cout<<1;
			else cout<<0;
		}
		if(b[2]=='E'){
			if(d[2]=='D')cout<<1;
			else cout<<0;
		}
	}
	else{
		cout<<0;
	}
} 
