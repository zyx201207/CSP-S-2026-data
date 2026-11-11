#include<bits/stdc++.h>
using namespace std;
int ac,bc;
string as,bs;
bool a,b,c,d;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ac>>as>>bc>>bs;
	if(ac==bc) a=1;
	if(a&&as[0]==bs[0]&&as[1]==bs[1]) b=1;
	if(b&&((as[2]-'A'<=2&&bs[2]-'A'<=2)||(as[2]-'A'>2&&bs[2]-'A'>2))) c=1;
	if(c&&(as[2]-bs[2]==1||(as[2]-bs[2]==-1)))d=1;
	cout<<(int)a<<(int)b<<(int)c<<(int)d;
	return 0;
 } 
