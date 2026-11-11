#include<bits/stdc++.h>
using namespace std;
int c1,c2,sp1,sp2;
string s1,s2;
char sl1,sl2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	sp1=s1[0]*10+s1[1];
	sp2=s2[0]*10+s2[1];
	sl1=s1[2];
	sl2=s2[2];
	if(sl1=='D') sl1='E';
	if(sl2=='D') sl2='F';
	if(c1==c2) cout<<1;
	else cout<<0;
	if(c1==c2&&sp1==sp2) cout<<1;
	else cout<<0;
	if(c1==c2&&sp1==sp2&&(((sl1=='A'||sl1=='B'||sl1=='C')&&(sl2=='A'||sl2=='B'||sl2=='C'))||((sl1=='E'||sl1=='F')&&(sl2=='E'||sl2=='F')))) cout<<1;
	else cout<<0;
	if(c1==c2&&sp1==sp2&&(((sl1=='A'||sl1=='B'||sl1=='C')&&(sl2=='A'||sl2=='B'||sl2=='C'))||((sl1=='E'||sl1=='F')&&(sl2=='E'||sl2=='F')))&&(sl1-sl2==1||sl2-sl1==1)) cout<<1;
	else cout<<0;
	return 0;
}
