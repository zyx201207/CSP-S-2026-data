#include <bits/stdc++.h>
using namespace std;

int a,b,c,d;
char s,t;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>s>>c>>d>>t;
	 
	if(a==c)cout<<1;
	else cout<<0;
	if(b==d)cout<<1;
	else cout<<0;
	if(a==c&&b==d&&((s<='C'&&t<='C')||(s>='D'&&t>='D')))
		cout<<1;
	else cout<<0;
	if(abs((int)s-(int)t)==1) cout<<1;
	else cout<<0;
	return 0;
} 
