#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r" ,stdin);
	freopen("travel.out","w" ,stdout);
	string r,rx,x,xx;
	int chr=0,chx=0,cr=0,cx=0;
	cin>>r>>rx>>x>>xx;
	if(r==x) cout<<1;
	else cout<<0; 
	chr=r/10;
	chx=x/10;
	cr=rx%100;
	cx=xx%100;
	if(chr==chx) cout<<1;
	else cout<<0;
	if((cr=='A'||cr=='B'||cr=='c')&&(cx=='A'||cx=='B'||cx=='c')) {
		cout<<1;
		if((cr=='B'||cr=='c')&&(cx=='A'||cx=='B'||)) cout<<1;
		else cout<<0;
	}
	else if((cr=='D'||cr=='F')&&(cx=='F'||cx=='D')) cout<<1<<1;
	else cout<<0<<0;
	return 0;
}
