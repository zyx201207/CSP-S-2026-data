#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char e,f;
	cin>>a>>b>>e>>c>>d>>f;
	
	if(a==c)printf("1");
	else {
		printf("0000");
		return 0;
	}
	
	if(b==d)printf("1");
	else {
		printf("000");
		return 0;
	}
	
	if(e=='A'||e=='B'||e=='C'){
		if(f=='A'||f=='B'||f=='C'){
		    printf("1");
		    if(f=='B'||e=='B')printf("1");
		    else printf("0");
		    return 0;
		}
		else {
			printf("00");
			return 0;
		}
	}
	else if(f=='D'||f=='F'){
		printf("11");
	}
	else printf("00");
	return 0;
}
