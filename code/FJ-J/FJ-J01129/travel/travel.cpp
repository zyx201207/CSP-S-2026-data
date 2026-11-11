#include <bits/stdc++.h>
using namespace std;
string a,b,c,d,n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	char x=b[2],y=d[2];
	n=b[0]+b[1],m=d[0]+d[1];
	if(a==c)cout<<1;
	else cout<<0;	
	if(a==c&&n==m)cout<<1;
	else cout<<0;
	if(a==c&&n==m&&((x>='A'&&x<='C'&&y>='A'&&y<='C')||(x>='D'&&x<='F'&&y>='D'&&y<='F')))
		cout<<1;
	else cout<<0;
	if(a==c&&n==m&&((x>='A'&&x<='C'&&y>='A'&&y<='C')||(x>='D'&&x<='F'&&y>='D'&&y<='F'))
	&&abs(int(x-y))==1)cout<<1;
	else cout<<0;
	return 0;
}
