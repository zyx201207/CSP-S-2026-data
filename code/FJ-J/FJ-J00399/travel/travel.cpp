#include<bits/stdc++.h>
using namespace std;
char a,b,m,n;
int c,d,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b;
	c=(a-'0')*10+(b-'0');
	cin>>a>>b>>m;
	x=(a-'0')*10+(b-'0');
	cin>>a>>b;
	d=(a-'0')*10+(b-'0');
	cin>>a>>b>>n;
	y=(a-'0')*10+(b-'0');
	if(c==d){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c==d&&x==y){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c==d&&x==y&&((m<='C'&&n<='C')||(m>'C'&&n>'C'))){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c==d&&x==y&&((m<='C'&&n<='C')||(m>'C'&&n>'C'))&&abs(abs(m-'C')-abs(n-'C'))==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
