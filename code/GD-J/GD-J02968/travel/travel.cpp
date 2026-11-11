#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int q,w,e,r;
char m,n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else
	{
		cout<<"0000";
		return 0;	
	}
	q=int(b[0])-'0';
	w=int(b[1])-'0';
	e=int(d[0])-'0';
	r=int(d[1])-'0';
	m=b[2];
	n=d[2];
	if(q==e&&w==r) cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if((m=='C'&&n=='A')||(m=='C'&&n=='B')||(m=='A'&&n=='B')||(m=='A'&&n=='C')||(m=='B'&&n=='C')||(m=='B'&&n=='A')||(m=='D'&&n=='F')||(m=='F'&&n=='D'))
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(int(m)+1==int(n)||int(m)-1==int(n)||(m=='D'&&n=='F')||(m=='F'&&n=='D'))
	{
		if((m=='C'&&n=='D')||(m=='D'&&n=='C')) cout<<0;
		else cout<<1;
	}
	else cout<<0;
	return 0;
}
