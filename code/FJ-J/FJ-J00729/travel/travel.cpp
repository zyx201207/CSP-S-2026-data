#include<bits/stdc++.h>
using namespace std;
int a,b;
string sa,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>sa>>b>>sb;
	char c1=sa[2],c2=sb[2];
	if(a==b) printf("1");
	else{
		printf("0000");
		return 0;
	}
	if(sa.substr(0,2)==sb.substr(0,2)) printf("1");
	else printf("0");
	if(sa.substr(0,2)==sb.substr(0,2)&&(c1<='C'&&c2<='C'||c1>='D'&&c2>='D')) printf("1");
	else printf("0");
	if(c1=='A'&&c2=='B'||c1=='B'&&c2=='C'||c1=='F'&&c2=='D'||c2=='A'&&c2=='B'||c2=='B'&&c1=='C'||c2=='F'&&c1=='D') printf("1");
	else printf("0");
	return 0;
}
