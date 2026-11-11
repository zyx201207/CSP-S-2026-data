#include<bits/stdc++.h>
using namespace std;
#define ulp(i,a,b) for(int i=a;i<=b;i++)
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	int x,y;
	if('A'<=s1[2]&&s1[2]<='C')x=1;
	else x=2;
	if('A'<=s2[2]&&s2[2]<='C')y=1;
	else y=2;
	if(c1!=c2){
		puts("0000");
	}
	else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		puts("1000");
	}
	else if(x!=y){
		puts("1100");
	}
	else if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
		puts("1110");
	}
	else puts("1111");
}
