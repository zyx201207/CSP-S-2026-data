#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) printf("1");
	else printf("0");
	int x,y;
	x=(b[0]-'0')*10+b[1]-'0';
	y=(d[0]-'0')*10+d[1]-'0';
	if(a==c && x==y) printf("1");
	else printf("0");
	int an=b[2]-'A'+1,bn=d[2]-'A'+1;
	if(a==c && x==y && ((an<=3 && bn<=3)||(an>=4&&bn>=4))) printf("1");
	else printf("0");
	if(x==y && abs(b[2]-d[2])==1 && !(b[2]=='D' && d[2]!='C') && !(d[2]=='D' && b[2]=='C'))
		printf("1");
	else printf("0");
	return 0;
}
