#include <iostream>
#include <cstdio>
using namespace std;
int a=0,b=0,c=0,d=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char p,q,bh1,bh2;
	cin>>a>>p>>q>>bh1;b=(p-'0')*10+(q-'0');
	cin>>c>>p>>q>>bh2;d=(p-'0')*10+(q-'0');
	if (bh1>bh2)swap(bh1,bh2);
	cout<<(a==c);
	cout<<(a==c&&b==d);
	cout<<(a==c&&b==d&&((bh1>='A'&&bh2>='A'&&bh1<='C'&&bh2<='C')||(bh1>='D'&&bh2>='D'&&bh1<='F'&&bh2<='F')));
	cout<<(a==c&&b==d&&((bh1=='A'&&bh2=='B')||(bh1=='B'&&bh2=='C')||(bh1=='D'&&bh2=='F')));
	return 0;
}
