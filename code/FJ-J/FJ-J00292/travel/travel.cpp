#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a="",b="",c="",d="";
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//system("diff a.in b.in");
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1])cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&((d[2]>='A'&&d[2]<='C'&&b[2]>='A'&&b[2]<='C')||(d[2]>='D'&&d[2]<='F'&&b[2]>='D'&&b[2]>='F')))cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&((d[2]>='A'&&d[2]<='C'&&b[2]>='A'&&b[2]<='C')||(d[2]>='D'&&d[2]<='F'&&b[2]>='D'&&b[2]>='F'))&&abs(d[2]-b[2])==1)cout<<1;
	else cout<<0;
	return 0;
}


