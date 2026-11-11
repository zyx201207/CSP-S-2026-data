#include<bits/stdc++.h>
using namespace std;
string s;
int a,b,xa,ya,xb,yb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	a=(s[0]-'0')*10+s[1]-'0';
	cin>>s;
	xa=(s[0]-'0')*10+s[1]-'0';
	ya=s[2]-'A'+1;
	cin>>s;
	b=(s[0]-'0')*10+s[1]-'0';
	cin>>s;
	xb=(s[0]-'0')*10+s[1]-'0';
	yb=s[2]-'A'+1;
	if(a==b){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(xa==xb&&a==b){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(xa==xb&&a==b&&((1<=ya&&ya<=3&&1<=yb&&yb<=3)||(4<=ya&&ya<=5&&4<=yb&&yb<=5))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(xa==xb&&a==b&&((1<=ya&&ya<=3&&1<=yb&&yb<=3)||(4<=ya&&ya<=5&&4<=yb&&yb<=5))&&abs(ya-yb)==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
