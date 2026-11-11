#include<bits/stdc++.h>
using namespace std;
struct node{
	string c,s;
	int p,b;
	char h;
}a[2];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[0].c>>a[0].s>>a[1].c>>a[1].s;
	for(int i=0;i<2;i++){
		a[i].p=a[i].s[0]*10+a[i].s[1];
		a[i].h=a[i].s[2];
	}
	bool q=true;
	if(a[0].c==a[1].c) cout<<1;
	else{
		cout<<0;
		q=false;
	}if(q && a[0].p==a[1].p) cout<<1;
	else{
		cout<<0;
		q=false;
	}
	bool l=true;
	if((a[0].h=='A' || a[0].h=='B' || a[0].h=='C') && (a[1].h=='D' || a[1].h=='F') || (a[1].h=='A' || a[1].h=='B' || a[1].h=='C') && (a[0].h=='D' || a[0].h=='F')) l=false;
	if(q && l) cout<<1;
	else{
		cout<<0;
		q=false;
	}
	for(int i=0;i<2;i++) a[i].b=int(a[i].h)-68;
	if(q && (a[0].b<4 && max(a[0].b,a[1].b)-min(a[0].b,a[1].b)==1) || (a[0].b>3) && max(a[0].b,a[1].b)-min(a[0].b,a[1].b)==2) cout<<1;
	else cout<<0;
	return 0;
 } 
