#include<bits/stdc++.h>
#define ll long long
using namespace std;
string x,y,c,s;
char z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y>>c>>s;
	z1=y[2],z2=s[2];
	if(x==c){
		printf("1");
	}else{
		printf("0000");
		return 0;
	}
	if(y[0]==s[0]&&y[1]==s[1]){
		printf("1");
	}else{
		printf("000");
		return 0;
	}
	if(('A'<=z1&&z1<='C'&&'A'<=z2&&z2<='C')||('D'<=z1&&z1<='F'&&'D'<=z2&&z2<='F')){
		printf("1");
	}else{
		printf("00");
		return 0;
	}
	if(abs(z1-z2)==1) printf("1");
	else printf("0");
	return 0;
}
