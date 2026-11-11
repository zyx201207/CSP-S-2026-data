#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b,c,d,e,g;
char f,h;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("traval.in","r",stdin);
	freopen("traval.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	e=b[0]+b[1];
	g=d[0]+d[1];
	f=b[2];
	h=d[2];
	if(e==g){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if((f<='C'&&h<='C')||(f>'C'&&h>'C')){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(f+1==h||h+1==f) cout<<1;
	else cout<<0;
	return 0;
}
