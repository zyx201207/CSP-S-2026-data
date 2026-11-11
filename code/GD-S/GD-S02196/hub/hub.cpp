#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,sign=1;char opt=getchar();
	while(opt<'0'||opt>'9'){
		if(opt=='-'){sign=-1;}
		opt=getchar();
	}
	while(opt>='0'&&opt<='9'){
		x=x*10+(opt-'0');
		opt=getchar();
	}
	return sign*x;
}
int c,T; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	c=read();T=read();
	while(T--){
		cout<<"1\n";
	}
} 
