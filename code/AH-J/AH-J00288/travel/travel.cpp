#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char ch1,ch2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>ch1>>c>>d>>ch2;
	if(a==c)cout<<1;
	else cout<<0;
	if(a==c&&b==d)cout<<1;
	else cout<<0;
	if(a==c&&b==d&&((ch1<='C'&&ch2<='C')||(ch1>='D'&&ch2>='D')))cout<<1;
	else cout<<0;
	if(a==c&&b==d&&((ch1<='C'&&ch2<='C')||(ch1>='D'&&ch2>='D'))&&abs(ch1-ch2)==1)cout<<1;
	else cout<<0;
	return 0;
}
