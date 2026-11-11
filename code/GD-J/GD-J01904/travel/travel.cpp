#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
int num1,num;
bool p1,p2,p3,p4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	p1=(a==c);
	p2=(b[0]==d[0]&&b[1]==d[1])&p1;
	char c1=b[2],c2=d[2];
	if(c1>='D'&&c1<='F'&&c2>='A'&&c2<='C'||c2>='D'&&c2<='F'&&c1>='A'&&c1<='C')p3=0;
	else p3=p2&1;
	p4=((int)(abs(b[2]-d[2]))==1)&p3;
	cout<<p1<<p2<<p3<<p4;
	return 0;
}

