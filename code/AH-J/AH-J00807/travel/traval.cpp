#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
char ch1,ch2;int a1,a2,b1,b2;
int main()
{
	freopen("traval.in","r",stdin);
	freopen("traval.out","w",stdout);
	scanf("%02d %02d%c %02d %02d%c",&a1,&b1,&ch1,&a2,&b2,&ch2);
	int c1=int(ch1-'A'+1),c2=int(ch2-'A'+1);
	bool f1=0,f2=0;
	if(c1<=3) f1=1;
	else f1=0;
	if(c2<=3) f2=1;
	else f2=0;
	string ans;
	if(a1==a2) ans+='1';
	else ans+='0';
	if(b1==b2&&a1==a2) ans+='1';
	else ans+='0';
	if((!(f1^f2))&&b1==b2&&a1==a2) ans+='1';
	else ans+='0';
	if(abs(c1-c2)==1&&(!(f1^f2))&&b1==b2&&a1==a2) ans+='1';
	else ans+='0';
	cout<<ans;
	return 0;
}
