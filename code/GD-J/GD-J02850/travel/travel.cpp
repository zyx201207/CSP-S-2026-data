#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a1,a2,a3,a4;
bool o(){
	if(s2[2]=='A' and (s4[2]=='B' or s4[2]=='C'))return 1;
	if(s2[2]=='B' and (s4[2]=='A' or s4[2]=='C'))return 1;
	if(s2[2]=='C' and (s4[2]=='B' or s4[2]=='A'))return 1;
	if(s2[2]=='D' and s4[2]=='E')return 1;
	if(s2[2]=='E' and s4[2]=='D')return 1;
	return 0;
}
bool u(){
	if(s2[2]=='E' or s2[2]=='D' or s2[2]=='B')return 1;
	if(s2[2]=='A' and s4[2]=='B')return 1;
	if(s2[2]=='C' and s4[2]=='B')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	for(int i=0;i<2;i++){
		a1*=10;
		a1+=(s1[i]-'0');
		a2*=10;
		a2+=(s2[i]-'0');
		a3*=10;
		a3+=(s3[i]-'0');
		a4*=10;
		a4+=(s4[i]-'0');
	}
	if(a1==a3)printf("1");
	else printf("0");
	if(a1==a3 && a2==a4)printf("1");
	else printf("0");
	if(a1==a3 && a2==a4 && o())printf("1");
	else printf("0");
	if(a1==a3 && a2==a4 && o() && u())printf("1");
	else printf("0");
}
