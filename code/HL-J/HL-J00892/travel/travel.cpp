#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool check();
bool check2();
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool f1,f2,f3;
	f1=f2=f3=false;
	cin>>a>>b>>c>>d;
	if(a==c){f1=true;cout<<1;}
	else cout<<0;
	if(f1&&b[0]==d[0]&&b[1]==d[1]){f2=true;cout<<1;}
	else cout<<0;
	if(f1&&f2&&check()){f3=true;cout<<1;}
	else cout<<0;
	if(f1&&f2&&f3&&check2()){cout<<1;}
	else cout<<0;
	return 0;
}
bool check(){
	if((b[2]=='F'||b[2]=='D')&&(d[2]=='F'||d[2]=='D'))
		return true;
	if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&
	   (d[2]=='A'||d[2]=='B'||d[2]=='C'))
		return true;
	return false;
}
bool check2(){
	if((b[2]=='F'||b[2]=='D')&&(d[2]=='F'||d[2]=='D'))
		return true;
	if(b[2]=='B'||d[2]=='B') return true;
	return false;
}