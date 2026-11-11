#include<bits/stdc++.h>
using namespace std;
int a,b;
int x,y;
char c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>c1>>b>>y>>c2;
	if(a==b){
		cout<<1;
	}else{
		cout<<0;
	}
	if(x==y and a==b){
		cout<<1;
	}else{
		cout<<0;
	}
	bool f=0;
	if(x==y and a==b){
		if(c1=='A' or c1=='B' or c1=='C'){
			if(c2=='A' or c2=='B' or c2=='C'){
				f=1;
				cout<<1;
			}
			else cout<<0;
		}else{
			if(c2=='D' or c2=='F'){
				f=1;
				cout<<1;
			}
			else cout<<0;
		}
	}else{
		cout<<0;
	}
	if(x==y and a==b and f){
		if(c1=='D' or c1=='F'){
			cout<<1;
		}else{
			if(abs(int(c1)-int(c2))==1){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<0;
	}
	return 0;
} 
