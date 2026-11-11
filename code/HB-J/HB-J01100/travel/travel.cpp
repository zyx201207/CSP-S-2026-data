#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
int l,o,p,r;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		l=1;
	}
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&l){
		cout<<1;
		o=1;
	}
	else cout<<0;
	if(((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D'))&&o){
		cout<<1;
		p=1;
	}
	else cout<<0;
	if(((b[2]+1==d[2]||d[2]+1==b[2])&&(b[2]!='C'&&d[2]!='D')&&(b[2]!='D'&&d[2]!='C'))&&p){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
