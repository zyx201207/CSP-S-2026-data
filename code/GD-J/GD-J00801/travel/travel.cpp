#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int n,m,x,y,s;
char ch1,ch2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	n=a[0]*10+a[1];
	m=c[0]*10+c[1];
	if(n==m)cout<<1;
	else {
		cout<<"0000";return 0;
	}
	x=b[0]*10+b[1];
	y=d[0]*10+d[1];
	if(x==y)cout<<1;
	else {
		cout<<"000";return 0;
	}
	ch1=b[2];
	ch2=d[2];
	if(ch1>='D'&&ch2>='D'){
		cout<<"11";return 0;
	}
	else if(ch1<'D'&&ch2<'D')cout<<"1";
	else {
		cout<<"00";return 0;
	}
	s=ch1-ch2;
	if(abs(s)==1)cout<<1;
	else cout<<0;
	return 0;
}
