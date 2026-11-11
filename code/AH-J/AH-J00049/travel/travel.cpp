#include<bits/stdc++.h>
using namespace std;
int rx,xx;
string rz,xz;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>rx>>rz>>xx>>xz;
	if(rx==xx) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(rz[0]==xz[0]&&rz[1]==xz[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	a=rz[2],b=xz[2];
	if(a>b) swap(a,b);
	if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='E')){
		cout<<11;
	}
	else if(a=='A'&&b=='C'){
		cout<<10;
	}
	else{
		cout<<"00";
	}
	return 0;
}
