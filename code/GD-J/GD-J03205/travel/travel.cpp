#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a[300],f;
int chk(char x,char y)
{
	if(x=='A'&&y=='B') return 1;
	if(x=='B'&&y=='A') return 1;
	if(x=='B'&&y=='C') return 1;
	if(x=='C'&&y=='B') return 1;
	if(x=='D'&&y=='F') return 1;
	if(x=='F'&&y=='D') return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a['A']=1;a['B']=1;a['C']=1;a['D']=2;a['F']=2;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) printf("1"),f++;
	else printf("0");
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&f==1) printf("1"),f++;
	else printf("0");
	if(a[(int)s2[2]]==a[(int)s4[2]]&&f==2) printf("1"),f++;
	else printf("0");
	if(chk(s2[2],s4[2])&&f==3) printf("1");
	else printf("0");
	return 0;
}
