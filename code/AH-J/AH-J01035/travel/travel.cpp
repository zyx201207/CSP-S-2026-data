#include <bits/stdc++.h>
using namespace std;
using LL=long long;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) printf("1");
	else printf("0");
	
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]) printf("1");
		else printf("0");
	}
	else printf("0");
	
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')) printf("1");
		else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')) printf("1");
		else printf("0");
	}else printf("0");
	
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')){
			if(labs(LL(s1[2])-LL(s2[2]))==1) printf("1");
			else printf("0");
		}else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
			if(labs(LL(s1[2])-LL(s2[2]))==2) printf("1");
			else printf("0");
		}else printf("0");
	}else printf("0");
	
	return 0;
}
