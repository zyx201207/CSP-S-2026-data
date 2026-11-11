#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r;
	cin >> r;
	char s;
	cin >> s;
	char a,b,c;
	cin >> a >> b >> c;
	cin >> s;
	string r2;
	cin >> r2;
	cin >> s;
	char a1,b1,c1;
	cin >> a1 >> b1 >> c1;
	if(r==r2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(r==r2&&a1==a&&b==b1){
		cout<<1;
	}else{
		cout<<0;
	}
	if(r==r2&&a1==a&&b==b1){
		if(c>='A'&&c<='C'&&c1>='A'&&c1<='C'){
			cout<<1;
		}
		else if(c>='D'&&c<='F'&&c1>='D'&&c1<='F'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(r==r2&&a1==a&&b==b1){
		if(c>='D'&&c<='F'&&c1>='D'&&c1<='F'){
			cout<<1;
		}
		if((c=='A'&&c1=='B')||(c1=='A'&&c=='B')||(c=='C'&&c1=='B')||(c=='B'&&c1=='C')){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
