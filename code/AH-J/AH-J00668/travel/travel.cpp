#include <bits/stdc++.h>
using namespace std;
string s,ss,c,cc;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c!=cc){
		printf("0000");
	}
	else {
		printf("1");
		if(s[0]==ss[0]&&s[1]==ss[1]){
			printf("1");
			if((s[2]>='A'&&s[2]<='C'&&ss[2]>='A'&&ss[2]<='C')||(s[2]>='D'&&s[2]<='F'&&ss[2]>='D'&&ss[2]<='F')){
				printf("1");
				if(abs(s[2]-ss[2])==1){
					printf("1");
				}
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	return 0;
} 
