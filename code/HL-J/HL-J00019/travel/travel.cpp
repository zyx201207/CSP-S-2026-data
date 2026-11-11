#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		printf("1");
		if(b[0]==d[0]&&b[1]==d[1]){
			printf("1");
			int x=b[2]-'A',y=d[2]-'A';
			if((x<=2&&y<=2)||(x>2&&y>2)){
				printf("1");
				if(abs(x-y)==1) printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}