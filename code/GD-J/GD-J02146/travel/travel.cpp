#include<bits/stdc++.h>
using namespace std;
bool b=1,b2=1,b3=0,b4=0;
char s1[5],s2[5],c1[5],c2[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s",c1+1);
	scanf("%s",s1+1);
	scanf("%s",c2+1);
	scanf("%s",s2+1);
	for(int i=1;i<=2;i++)
	{
		if(c1[i]!=c2[i]) b=0;
		if(s1[i]!=s2[i]) b2=0;
	}
    if(s1[3]<='C'&&s2[3]<='C') b3=1;
    else if(s1[3]>'C'&&s2[3]>'C') b3=1;
    if(abs(int(s1[3])-int(s2[3]))==1) b4=1;
	if(b==0) b2=0;
	if(b2==0) b3=0;
	if(b3==0) b4=0;
	cout<<b<<b2<<b3<<b4;
	return 0;
}
