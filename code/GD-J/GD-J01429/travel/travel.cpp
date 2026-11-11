#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	if(c==cc) printf("1");
	else printf("0");
	if(s[0]==ss[0] and s[1]==ss[1] and c==cc){
		printf("1");
	}
	else printf("0");
	if(c==cc and s[0]==ss[0] and s[1]==ss[1] and (s[2]>='A' and s[2]<='C' and ss[2]>='A' and ss[2]<='C'||s[2]>='D' and s[2]<='F' and ss[2]>='D' and ss[2]<='F')){
		printf("1");
	}
	else cout<<0;
	if(c==cc and s[0]==ss[0] and s[1]==ss[1] and (s[2]>='A' and s[2]<='C' and ss[2]>='A' and ss[2]<='C'||s[2]>='D' and s[2]<='F' and ss[2]>='D' and ss[2]<='F') and abs(s[2]-ss[2])==1) printf("1");
	else printf("0");
	return 0;
}
