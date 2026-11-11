#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
char n,m;
int x,y;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	x=(b[0]-'0')*10+(b[1]-'0');
	y=(d[0]-'0')*10+(d[1]-'0');
	n=b[2];
	m=d[2];
	if(x!=y){
		cout<<"000";
		return 0;
	} 
	cout<<1;
	if((n>='A'&&n<='C'&&m>='A'&&m<='C')||(n>='D'&&n<='E'&&m>='D'&&m<='E')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(n+1==m||m+1==n) cout<<1;
	else cout<<0;
	return 0;
}
