#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rs,xc,xs;
	cin>>rc>>rs>>xc>>xs;
	int xiang=1,pai=1,ce=0,ai=0;
	for (int i=0;i<=1;i++){
		if (rc[i]!=xc[i]){
			xiang=0;
		}
	}
	if (xiang==0){
		cout<<0<<0<<0<<0;
		return 0;
	}
	for (int i=0;i<=1;i++){
		if (rs[i]!=xs[i]){
			pai=0;
		}
	}
	if (pai==0){
		cout<<1<<0<<0<<0;
		return 0;
	}
	if (((rs[2]=='A') && (xs[2]=='B')) || ((rs[2]=='B') && (xs[2]=='A')) || ((rs[2]=='A') && (xs[2]=='C')) || ((rs[2]=='C') && (xs[2]=='A')) || ((rs[2]=='B') && (xs[2]=='C')) || ((rs[2]=='C') && (xs[2]=='B')) || ((rs[2]=='D') && (xs[2]=='E')) || ((rs[2]=='E') && (xs[2]=='D'))){
		ce=1;
	}
	else {
		cout<<1<<1<<0<<0;
		return 0;
	}
	if (((rs[2]=='A') && (xs[2]=='B')) || ((rs[2]=='B') && (xs[2]=='C')) || ((rs[2]=='D') && (xs[2]=='E')) || ((rs[2]=='E') && (xs[2]=='D')) || ((rs[2]=='C') && (xs[2]=='B')) || ((rs[2]=='B') && (xs[2]=='A'))){
		ai=1;
		cout<<1<<1<<1<<1;
		return 0;
	}
	else{
		cout<<1<<1<<1<<0;
		return 0;
	}
	return 0;
}
