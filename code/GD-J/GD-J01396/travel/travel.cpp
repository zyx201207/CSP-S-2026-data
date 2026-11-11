#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r,x,rs,xs;
	char rc,xc;
	cin>>r>>rs>>rc>>x>>xs>>xc;
	if(r==x&&rs==xs&&abs(rc-xc)==1&&(rc<='C'&&xc<='C'||rc>='D'&&xc>='D'))cout<<"1111";
	else if(r==x&&rs==xs&&(rc<='C'&&xc<='C'||rc>='D'&&xc>='D'))cout<<"1110";
	else if(r==x&&rs==xs)cout<<"1100";
	else if(r==x)cout<<"1000";
	else cout<<"0000";
	return 0;
} 
