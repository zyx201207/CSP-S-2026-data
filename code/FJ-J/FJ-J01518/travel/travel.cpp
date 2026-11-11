#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int e=0,f=0,g=0,h=0,tca=0,tcb=0;
	cin>>a>>b>>c>>d;
	if(b[2]=='F'||b[2]=='D'){
		tca=1;
	}
	if(d[2]=='F'||d[2]=='D'){
		tcb=1;
	}
	if(a[0]==c[0]&&a[1]==c[1]){
		e=1;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&e==1){
		f=1;
	}
	if(tca==tcb&&f==1){
		g=1;
	}
	if(tca==1&&tcb==1&&g==1||b[2]-d[2]==1&&g==1||d[2]-b[2]==1&&g==1){
		h=1;
	}
	cout<<e<<f<<g<<h;
	return 0;
}
