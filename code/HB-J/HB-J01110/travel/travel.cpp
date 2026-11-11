#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b,c,d;
bool fa,fb,fc,fd;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c) fa=1;
	string xa="",xb="";
	xa+=b[0];xa+=b[1];
	xb+=d[0];xb+=d[1];
	if(fa&&xa==xb) fb=1;
	if(fb&&!((b[2]=='D'&&d[2]=='C')||(b[2]=='C'&&d[2]=='D'))) fc=1;
	if(fc&&(b[2]+1==d[2]||d[2]+1==b[2]||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')))fd=1;
	cout<<int(fa)<<int(fb)<<int(fc)<<int(fd); 
	return 0;
}
