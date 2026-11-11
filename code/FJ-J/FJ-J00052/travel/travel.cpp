#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char ss1,ss2;
	scanf("%d%d %c %d%d %c",&c1,&s1,&ss1,&c2,&s2,&ss2);
	//cin>>c1>>s1>>ss1>>c2>>s2>>ss2;
	/*
	string s;
	cin>>s;
	cout<<s;
	c1=(s[0]-'0')*10+(s[1]-'0');
	s1=(s[3]-'0')*10+(s[4]-'0');
	ss1=s[5];
	c2=(s[7]-'0')*10+(s[8]-'0');
	s2=(s[9]-'0')*10+(s[10]-'0');
	ss2=s[11];
	*/
	//printf("%d %d%c %d %d%c",c1,s1,ss1,c2,s2,ss2);
	if(c1==c2)printf("1");
	else printf("0");
	if(c1==c2&&s1==s2)printf("1");
	else printf("0");
	if((c1==c2&&s1==s2)&&( ( (ss1=='A'||ss1=='B'||ss1=='C') && (ss2=='A'||ss2=='B'||ss2=='C') ) || ( (ss1=='D'||ss1=='F') && (ss2=='D'||ss2=='F') )))printf("1");
	else printf("0");
	if((c1==c2&&s1==s2)&&( (ss1=='A'&&ss2=='B') || (ss1=='B'&&ss2=='A') || (ss1=='B'&&ss2=='C') || (ss1=='C'&&ss2=='B') || (ss1=='D'&&ss2=='F') || (ss1=='F'&&ss2=='D') ) )printf("1");
	else printf("0");
	return 0;
}
