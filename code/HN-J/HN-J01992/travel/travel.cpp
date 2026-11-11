#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int x=b[2]-'A',y=d[2]-'A';
	if(a!=c) printf("0000");
	else if(b[0]!=d[0]||b[1]!=d[1]) printf("1000");
	else if(x<3&&y>=3||x>=3&&y<3) printf("1100");
	else if(abs(x-y)>1) printf("1110");
	else printf("1111");
	return 0;
}
