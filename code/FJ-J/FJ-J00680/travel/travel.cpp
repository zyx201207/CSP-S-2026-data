#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;int b1,b2,l1,l2;
	if(s1[0]==0)l1=s1[1]-'0';else l1=10+(s1[1]-'0');
	if(s2[0]==0)l2=s2[1]-'0';else l2=10+(s2[1]-'0');
	char z1,z2; z1=s1[2],z2=s2[2];
	if(c1==c2)cout<<1; else cout<<0;
	if(c1==c2&&l1==l2)cout<<1;else cout<<0;
	if(c1==c2&&l1==l2&&((z1>'C'&&z2>'C')||(z1<='C'&&z2<='C')))cout<<1;else cout<<0;
	if(c1==c2&&l1==l2&&((z1>'C'&&z2>'C')||(z1<='C'&&z2<='C'))&&abs(z1-z2)==1)cout<<1;else cout<<0;
	cout<<endl;
	return 0;
}
