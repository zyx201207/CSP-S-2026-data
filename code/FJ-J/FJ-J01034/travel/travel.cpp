#include<bits/stdc++.h>
using namespace std;
int c1,c2,p1,p2;
char a,b; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>p1>>a>>c2>>p2>>b;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(p1==p2&&c1==c2)cout<<1;
	else cout<<0;
	int z=0,zz=0;
	if(a=='A'||a=='B'||a=='C')z=1;
	if(b=='A'||b=='B'||b=='C')zz=1;
	if(z==zz&&p1==p2&&c1==c2)cout<<1;
	else cout<<0;
	if(a=='A'&&b=='B'&&p1==p2&&c1==c2){
		cout<<1;
		return 0;
	}
	if(a=='B'&&b=='A'&&p1==p2&&c1==c2){
		cout<<1;
		return 0;
	}
	if(a=='B'&&b=='C'&&p1==p2&&c1==c2){
		cout<<1;
		return 0;
	}
	if(a=='C'&&b=='B'&&p1==p2&&c1==c2){
		cout<<1;
		return 0;
	}
	if(a=='D'&&b=='F'&&p1==p2&&c1==c2){
		cout<<1;
		return 0;
	}
	if(a=='F'&&b=='D'&&p1==p2&&c1==c2){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
} 
