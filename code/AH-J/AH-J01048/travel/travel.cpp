#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a1=(c1[0]-'0')*10+(c1[1]-'0'),b1=(s1[0]-'0')*10+(s1[1]-'0');
	int a2=(c2[0]-'0')*10+(c2[1]-'0'),b2=(s2[0]-'0')*10+(s2[1]-'0');
	char d1=s1[2],d2=s2[2];
	int c=s1[2]-s2[2];
	c=abs(c);
	if(a1==a2) cout<<1;
	else cout<<0;
	if(a1==a2&&b1==b2) cout<<1;
	else cout<<0;
	if(a1==a2&&b1==b2&&((d1<='C'&&d2<='C')||(d1>='D'&&d2>='D')))cout<<1;
	else cout<<0;
	if(a1==a2&&b1==b2&&((d1<='C'&&d2<='C')||(d1>='D'&&d2>='D'))&&c==1) cout<<1;
	else cout<<0;
	return 0;
}
