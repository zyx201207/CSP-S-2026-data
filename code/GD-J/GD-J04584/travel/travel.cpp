#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define filename "travel"
const int N=1e5+5;
int a,b,c,d;
char x,y;
signed main(){
	fastio;
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	cin>>a>>b>>x>>c>>d>>y;
//	cout<<a<<b<<x<<c<<d<<y<<esndl;
	if(a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	if(b==d&&a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	if((x<='C'&&y<='C'||x>='D'&&y>='D')&&b==d&&a==c){
		cout<<1;
	}else{
		cout<<0;
	}
	if((x==(char)(y-1)||x==(char)(y+1))&&b==d&&a==c&&((x<='C'&&y<='C')||(x>='D'&&y>='D'))){
		cout<<1;
	}
	else{
		if((x=='D'&&y=='F')||(x=='F'&&y=='D')){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
