#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=1e5+5;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,t1,s2,t2;
	cin>>s1>>t1>>s2>>t2;
	if(s1==s2) printf("1");
	else{
		printf("0000");
		return 0;	
	} 
	int a=(t1[0]-'0')*10+(t1[1]-'0'),b=(t2[0]-'0')*10+(t2[1]-'0');
	if(a==b){
		printf("1");
	}else{
		printf("000");
		return 0;
	} 
	if((t1[2]>='A'&&t1[2]<='C'&&t2[2]>='A'&&t2[2]<='C')||(t1[2]>'C'&&t2[2]>'C')) printf("1");
	else{
		printf("00");
		return 0;
	} 
	if((abs(t1[2]-t2[2])==1||t1[2]=='D'&&t2[2]=='F'||t1[2]=='F'&&t1[2]=='D')&&((t1[2]!='C'||t2[2]!='D')&&(t1[2]!='D'||t2[2]!='C'))) printf("1");
	else printf("0");
	return 0;
} 
