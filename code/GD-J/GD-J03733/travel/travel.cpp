#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c)puts("0000");
	else if(b[0]!=d[0]||b[1]!=d[1])puts("1000");
	else if((b[2]<='C'&&d[2]>='D')||(b[2]<='C'&&d[2]>='D'))puts("1100");
	else if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))puts("1110");
	else puts("1111");
	return 0;
}
