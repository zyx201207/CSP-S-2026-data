#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return f*x;
}
string rc,rs,xc,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	int rp=(rs[0]-'0')*10+rs[1]-'0',xp=(xs[0]-'0')*10+xs[1]-'0';
	if(rc!=xc) cout<<"0000";
	else if(rp!=xp) cout<<"1000";
	else if((rs[2]>'C'&&xs[2]<'D')||(rs[2]<'D'&&xs[2]>'C')) cout<<"1100";
	else if(abs(rs[2]-xs[2])>1&&!(rs[2]=='D'&&xs[2]=='F')&&!(rs[2]=='F'&&xs[2]=='D')) cout<<"1110";
	else cout<<"1111";
	return 0;
}

