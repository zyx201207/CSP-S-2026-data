#include<bits/stdc++.h>
using namespace std;
int c1,c2,x,y;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>a>>c2>>b;
	for(int i=0;i<2;i++){
		x=x*10+a[i]-'0';
		y=y*10+b[i]-'0';
	}
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(x!=y){
		cout<<1000;
		return 0;
	}
	if(((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='D'||b[2]=='F'))||((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(a[2]=='D'||a[2]=='F'))){
		cout<<1100;
		return 0;
	}
	if((a[2]=='A'&&b[2]!='B')||(a[2]=='B'&&b[2]!='C')||(a[2]=='B'&&b[2]!='A')||(a[2]=='C'&&b[2]!='B')||(a[2]=='D'&&b[2]!='F')||(a[2]=='F'&&b[2]!='D')){
		cout<<1110;
		return 0;
	}
	else cout<<1111;
	return 0;
}

