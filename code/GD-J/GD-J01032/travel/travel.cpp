#include<bits/stdc++.h>
using namespace std;
string c0,c1;
char s0[10],s1[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c0>>s0>>c1>>s1;
	if(c0!=c1)printf("0000");
	else if(s0[0]!=s1[0]||s0[1]!=s1[1])printf("1000");
	else if((s0[2]>='D'&&s1[2]<='C')||(s0[2]<='C'&&s1[2]>='D'))printf("1100");
	else if((s0[2]+1==s1[2]))printf("1111");
	else if(s0[2]=='D'&&s1[2]=='F')printf("1111");
	else printf("1110");
	return 0;
}
