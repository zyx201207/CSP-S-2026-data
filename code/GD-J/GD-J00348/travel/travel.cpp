#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a,b,c,d;cin>>a>>b>>c>>d; 
	string s=b.substr(0,2),t=d.substr(0,2);
	if(a==c)	cout<<1;
	else	cout<<0;
	if(a==c&&s==t)	cout<<1;
	else	cout<<0;
	if(a==c&&s==t&&((b[2]>='D'&&d[2]>='D')||(b[2]<='C'&&d[2]<='C')))	cout<<1;
	else	cout<<0;
	if(a==c&&s==t&&((b[2]>='D'&&d[2]>='D')||(b[2]<='C'&&d[2]<='C'))&&abs(int(b[2])-int(d[2]))==1)	cout<<1;
	else	cout<<0;
	return 0;
}
