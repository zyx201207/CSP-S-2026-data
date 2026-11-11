#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d; 
	int x=(b[0]-'0')*10+(b[1]-'0');
	int y=(d[0]-'0')*10+(d[1]-'0');
	if(a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==c&&x==y){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==c&&x==y&&(((b[2]=='F'&&d[2]=='D')||(b[2]=='D'&&d[2]=='F'))||((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')&&(b[2]!=d[2])))){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==c&&x==y&&abs(int(b[2]-64)-int(d[2]-64))==1&&(((b[2]=='F'&&d[2]=='D')||(b[2]=='D'&&d[2]=='F'))||((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')&&(b[2]!=d[2])))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
