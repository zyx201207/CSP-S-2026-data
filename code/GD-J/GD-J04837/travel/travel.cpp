#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool a1,b1,c1,d1,n,m;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>a>>b>>c>>d;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		n=1;
	}else{
		n=0;
	}
	if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
		m=1;
	}else{
		m=0;
	}
	
	if(a==c){
		a1=1;
	}else{
		cout<<'0'<<'0'<<'0'<<'0';
		return 0;
	}
//	char s[20],s2[20];
	if(a1==1&&b[0]==d[0]&&b[1]==d[1]){
		b1=1;
	}else{
		cout<<'1'<<'0'<<'0'<<'0';
		return 0;
	}
	if(a1==1&&b1==1&&n==m){
		c1=1;
	}else{
		cout<<'1'<<'1'<<'0'<<'0';
		return 0;
	}
	
	if(c1==1&&n==0){
		d1=1;
	}
	if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')&&n==1){
		cout<<'1'<<'1'<<'1'<<'0';
		return 0;
	}
	if(a1==1&&b1==1&&c1==1&&d1==1){
		cout<<'1'<<'1'<<'1'<<'1';
	}
	
	return 0;
} 
