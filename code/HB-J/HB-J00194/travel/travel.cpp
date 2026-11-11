#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if((a[0]-'0')*10+a[1]-'0'==(c[0]-'0')*10+c[1]-'0'){
		printf("1");
		if((b[0]-'0')*10+b[1]-'0'==(d[0]-'0')*10+d[1]-'0'){
			printf("1");
			if((b[2]=='D'||b[2]=='F')+(d[2]=='D'||d[2]=='F')!=1){
				printf("1");
				if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')) printf("0");
				else printf("1");
			}else printf("00");
		}else printf("000");
	}else printf("0000");
	return 0;
}
