#include<bits/stdc++.h>
using namespace std;
string b,d;
int a,c;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	cout<<((a==c)?((b[0]==d[0]&&b[1]==d[1])?(((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='E'&&d[2]>='D'&&d[2]<='E'))?(((b[2]-1)==d[2]||(b[2]+1)==d[2])?"1111":"1110"):"1100"):"1000"):"0000");
	return 0; 
}
