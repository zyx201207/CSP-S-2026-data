#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>x>>c>>y>>d>>y;
	if(a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	if(b==d&&a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	if(b==d&&(((x>='D')&&(y>='D'))||((x<='C')&&(y<='C')))&&a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	if((((x>='D')&&(y>='D'))||((x<='C')&&(y<='C')))&&abs(x-y)==1&&b==d&&a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
