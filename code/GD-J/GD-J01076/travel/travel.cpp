#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&b!=d)cout<<1;
	else cout<<0;
	if(b!=d&&(b[0]==d[0]&&b[1]==d[1]) && ((b[2]>='A'&&b[2]<'D' && d[2]>='A'&&d[2]<'D')||(b[2]>='D'&&b[2]<='E' && d[2]>='D'&&d[2]<='E')))cout<<1;
	else cout<<0;
	if((((int)b[2]==(int)d[2]-1||(int)b[2]==(int)d[2]+1)&&(b[2]>='A'&&b[2]<'D' && d[2]>='A'&&d[2]<'D')||(b[2]>='D'&&b[2]<='E' && d[2]>='D'&&d[2]<='E'))&&(b[0]==d[0]&&b[1]==d[1]))cout<<1;
	else cout<<0;
	return 0;
} 
