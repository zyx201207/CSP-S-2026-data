#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>c>>d>>y;
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
	if(x>='A'&&x<='C'&&y>='A'&&y<='C'&&b==d&&a==c){
		cout<<1;
	}else if((x=='D'||x=='F')&&(y=='D'||y=='F')&&b==d&&a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	if((x=='D'||x=='F')&&(y=='D'||y=='F')&&b==d&&a==c){
		cout<<1;
	}else if((x=='A'||x=='B')&&(y=='A'||y=='B')&&b==d&&a==c){
		cout<<1;
	}else if((x=='B'||x=='C')&&(y=='B'||y=='C')&&b==d&&a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
