#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
int n,m,x,y;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	n=(a[0]-'0')*10+(a[1]-'0');
	m=(c[0]-'0')*10+(c[1]-'0');
	if(n==m){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	x=(b[0]-'0')*10+(b[1]-'0');
	y=(d[0]-'0')*10+(d[1]-'0');
	if(x==y){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(((b[2]=='A'||b[2]=='B')||b[2]=='C')&&(d[2]=='D'||d[2]=='F')){
		cout<<0<<0;
		return 0;
	}
	if(((d[2]=='A'||d[2]=='B')||d[2]=='C')&&(b[2]=='D'||b[2]=='F')){
		cout<<0<<0;
		return 0;
	}
	cout<<1;
	if(b[2]+1==d[2]||d[2]+1==b[2]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
