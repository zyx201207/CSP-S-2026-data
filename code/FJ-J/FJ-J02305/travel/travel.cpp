#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
int u1,t1,u2,t2;
int v1,v2;
//A=1,B=2,C=3,D=4,E=5
int tonum(char c){
	if(c=='A') return 1;
	if(c=='B') return 2;
	if(c=='C') return 3;
	if(c=='D') return 4;
	if(c=='E') return 5;
}
void inp(){
	cin>>c1>>s1>>c2>>s2;
	u1=(c1[0]-'0')*10+(c1[1]-'0');
	u2=(c2[0]-'0')*10+(c2[1]-'0');
	//u1,u2车箱数 
	t1=(s1[0]-'0')*10+(s1[1]-'0');
	t2=(s2[0]-'0')*10+(s2[1]-'0');
	//t1,t2第几排 
	v1=tonum(s1[2]),v2=tonum(s2[2]);
	//v1,v2第几位 
}
int side(int x){
	if(x<=3) return 1;
	if(x>=4) return 2;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	inp();
	bool f1=(u1==u2);
	cout<<f1;
	bool f2=f1&&(t1==t2);
	cout<<f2;
	bool f3=f2&&(side(v1)==side(v2));
	cout<<f3;
	bool f4=f3&&(abs(v1-v2)==1);
	cout<<f4;
	return 0;
}
