#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int A=0;
	int B=0;
	int C=0;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
		A=1;
	}else{
		cout<<0;
	}
	if(A==1&&b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
		B=1;
	}else{
		cout<<0;
	}
	if(B==1&&((b[2]=='B'&&d[2]=='A')||(b[2]=='A'&&d[2]=='B')||(b[2]=='A'&&b[2]=='C')||(b[2]=='C'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))){
		cout<<1;
		C=1;
	}else{
		cout<<0;
	}
	if(C==1&&(b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
