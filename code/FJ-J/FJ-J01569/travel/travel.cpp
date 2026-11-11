#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,y;
	int a,c;cin>>a>>x>>c>>y;
	if(a==c)cout<<1;
	else {
		cout<<"0000";return 0;
	}
	int b=int(x[0]-'0')*10+int(x[1]-'0'),d=int(y[0]-'0')*10+int(y[1]-'0');
	if(b==d){
		cout<<'1';
	}
	else {
		cout<<"000";return 0;
	}
	int n=x[2]-'A',m=y[2]-'A';
	if((n>=0&&n<=2&&m>=0&&m<=2)||(n>=3&&n<=5&&m>=3&&m<=5)){
		cout<<'1';
	}
	else {
		cout<<"00";return 0;
	}
	if(n>=3&&n<=4&&m>=3&&m<=5){
		cout<<'1';return 0;
	}
	if(abs(n-m)<=1){
		cout<<'1';return 0; 
	}
	cout<<'0';
    return 0;
	
	
	
	
}
