#include <bits\stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stetin);
	string n,m,x,y;
	cin>>n>>m>>x>>y;
	if(n==x)cout<<1;
	if(m[0]==y[0]&&m[1]==y[1])cout<<1;
	if(m[2]!='D'&&m[2]!='F'){
		if(y[2]!='F'&&y[2]!='D')cout<<1;
		else cout<<0;
	}
	else{
		if(y[2]=='F'||y[2]=='D')cout<<1;
		else cout<<0;
	}
	if(m[0]==y[0]&&m[1]==y[1]){
		if(m[2]=='A'&&y[2]=='B'){
			cout<<1;
		}
		else if(m[2]=='B'&&y[2]=='A'){
			cout<<1;
		}
		else if(m[2]=='B'&&y[2]=='C'){
			cout<<1;
		}
		else if(m[2]=='C'&&y[2]=='B'){
			cout<<1;
		}
		else if(m[2]=='D'&&y[2]=='F'){
			cout<<1;
		}
		else if(m[2]=='F'&&y[2]=='D'){
			cout<<1;
		}
		else cout<<0;
	}
	freopen("travel.out","w",sgtout);
	return 0;
}
