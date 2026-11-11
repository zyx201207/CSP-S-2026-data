//GZ-J00635 兴义市弘毅中学 廖鑫豪 
#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool s,n,m; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	s=(a==c);
	n=(b[0]==d[0]&&b[1]==d[1]);
	m=(b[2]<'D'&&d[2]<'D')||(b[2]>'C'&&d[2]>'C');
	if(s)	cout<<1;
	else	cout<<0;
	if(s&&n)	cout<<1;
	else	cout<<0;
	if(s&&n&&m)	cout<<1;
	else	cout<<0;
	if(s&&n&&m&&(b[2]+1==d[2]||b[2]-1==d[2]))	cout<<1<<'\n';
	else	cout<<0<<'\n';
	return 0;
} 
