#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	//ysjfNB
	cin>>a>>b>>c>>d;
	cout<<(a==c)<<(a==c&&b[1]==d[1]&&b[0]==d[0]);
	cout<<(a==c&&b[1]==d[1]&&b[0]==d[0]&&((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')));
	cout<<(a==c&&b[1]==d[1]&&b[0]==d[0]&&((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))&&abs(int(b[2]-d[2]))==1);
	return 0;
}
