#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		printf("1");
		if(b[0]==d[0]&&b[1]==d[1]){
			printf("1");
			char aa=b[2],bb=d[2];
			if(aa>bb) swap(aa,bb);
			if(aa=='D'&&bb=='F') printf("11");
			else if(aa=='A'&&bb=='B') printf("11");
			else if(aa=='A'&&bb=='C') printf("10");
			else if(aa=='A'&&bb=='D') printf("00");
			else if(aa=='A'&&bb=='F') printf("00");
			else if(aa=='B'&&bb=='C') printf("11");
			else if(aa=='B'&&bb=='D') printf("00");
			else if(aa=='B'&&bb=='F') printf("00");
			else if(aa=='C'&&bb=='D') printf("00");
			else if(aa=='C'&&bb=='F') printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
} 
