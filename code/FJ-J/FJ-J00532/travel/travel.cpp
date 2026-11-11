#include<bits/stdc++.h>
using namespace std;
int a1,b1;
string a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a1==b1 && a2[0]==b2[0] && a2[1]==b2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	char x=a2[2],b=b2[2];
	if(a1==b1 && a2[0]==b2[0] && a2[1]==b2[1] && (((x>='A'&&x<='C')&&(b>='A'&&b<='C')) || ((x>='D'&&x<='F')&&(b>='D'&&b<='F')))){
		cout<<1;
	}else{
		cout<<0;
	}
	int n=(a1==b1 && a2[0]==b2[0] && a2[1]==b2[1] && (((x>='A'&&x<='C')&&(b>='A'&&b<='C')) || ((x>='D'&&x<='F')&&(b>='D'&&b<='F'))));
	if(n && (((x=='A'&&b=='B')||(x=='B'&&b=='C')) || (x=='D'&&b=='F'))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
