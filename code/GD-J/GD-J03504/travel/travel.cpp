#include<bits/stdc++.h>
using namespace std;
const int N=200005;
string a,b,c,d;
bool A,B,C,D;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	A=a==c,B=A&&b[0]==d[0]&&b[1]==d[1],
	C=B&&(max(b[2],d[2])<='C'||min(b[2],d[2])>='D'),
	D=C&&(abs(b[2]-d[2])==1||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D');
	cout<<A<<B<<C<<D<<'\n';return 0;
}
