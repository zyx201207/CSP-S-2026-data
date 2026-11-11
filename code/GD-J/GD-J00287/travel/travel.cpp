#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool bj1,bj2,bj3,bj4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>a>>b>>c>>d;
	if(a==c) bj1=1;
	else bj1=0;
	if(bj1&&b[0]+b[1]==d[0]+d[1]) bj2=1;
	else bj2=0;
	if(bj1&&bj2&&((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))) bj3=1;
	else bj3=0;
	if(b[2]>d[2]) swap(b,d);
	if(bj1&&bj2&&bj3&&(
		(b[2]=='A'&&d[2]=='B')||
		(b[2]=='B'&&d[2]=='C')||
		(b[2]=='D'&&d[2]=='F'))) bj4=1;
	else bj4=0;
	cout<<bj1<<bj2<<bj3<<bj4;
	return 0;
}
