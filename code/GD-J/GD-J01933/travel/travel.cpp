#include<bits/stdc++.h>
using namespace std;
string sc,sz,tc,tz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sc>>sz>>tc>>tz;
	if(sc==tc){
		printf("1");
		if(sz.substr(0,2)==tz.substr(0,2)){
			printf("1");
			if((sz[2]=='A'&&(tz[2]=='B'||tz[2]=='C'))||(sz[2]=='B'&&(tz[2]=='A'||tz[2]=='C'))||(sz[2]=='C'&&(tz[2]=='B'||tz[2]=='A'))||(sz[2]=='D'&&tz[2]=='F')||(sz[2]=='D'&&tz[2]=='F')){
				printf("1");
				if(abs(sz[2]-tz[2])==1) printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}
