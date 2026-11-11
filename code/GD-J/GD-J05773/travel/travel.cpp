#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string a=s1.substr(0,2),b=s2.substr(0,2);
	if(c1!=c2) printf("0000");
	else if(a!=b) printf("1000");
	else if(!((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))) printf("1100");
	else if((abs(s1[2]-s2[2])==1)||(s1[2]>='D'&&s2[2]>='D')) printf("1111");
	else printf("1110");
	return 0;
}
