#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a0,a1,b0,b1;
	cin>>a0>>a1>>b0>>b1;
	if(a0!=b0) printf("0000");
	else if(b1[0]!=a1[0]||b1[1]!=a1[1]) printf("1000");
	else if((a1[2]<'D')!=(b1[2]<'D')) printf("1100");
	else if(abs(a1[2]-b1[2])==1||a1[2]+b1[2]=='D'+'F') printf("1111");
	else printf("1110");
	return 0;
}
