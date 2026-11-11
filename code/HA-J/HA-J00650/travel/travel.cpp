#include <bits/stdc++.h>
using namespace std;
char a1[110],a2[110];
char c1[110],c2[110];
bool is1(char aa,char bb)
{
	if(aa=='A'&&bb=='B') return 1;
	if(aa=='B'&&bb=='A') return 1;
	if(aa=='B'&&bb=='C') return 1;
	if(aa=='C'&&bb=='B') return 1;
	if(aa=='D'&&bb=='F') return 1;
	if(aa=='F'&&bb=='D') return 1;
	return 0;
}
bool is2(char aa,char bb)
{
	if(aa=='A'&&bb=='B') return 1;
	if(aa=='A'&&bb=='C') return 1;
	if(aa=='B'&&bb=='A') return 1;
	if(aa=='B'&&bb=='C') return 1;
	if(aa=='C'&&bb=='A') return 1;
	if(aa=='C'&&bb=='B') return 1;
	if(aa=='D'&&bb=='F') return 1;
	if(aa=='F'&&bb=='D') return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int ok1=0,ok2=0,ok3=0,ok4=0;
	scanf("%s",a1+1);scanf("%s",c1+1);
	scanf("%s",a2+1);scanf("%s",c2+1);
	if(a1[1]==a2[1]&&a1[2]==a2[2]) ok1=1;
	if(ok1==1&&c1[1]==c2[1]&&c1[2]==c2[2]) ok2=1;
	if(ok1==1&&ok2==1&&is2(c1[3],c2[3])) ok3=1;
	if(ok1==1&&ok2==1&&ok3==1&&is1(c1[3],c2[3])) ok4=1;
	cout<<ok1<<ok2<<ok3<<ok4<<endl;
	return 0;
}
