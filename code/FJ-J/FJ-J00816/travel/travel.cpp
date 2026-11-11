#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	ll x=int(b[0])*10+b[1],y=int(d[0])*10+d[1];
	char n=b[2],m=d[2];
	if(a==c){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(x==y){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	if((n<='C'&&m<='C')||(n>'C'&&m>'C')){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	if(int(n)+1==int(m)||int(n)-1==int(m)){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
} 
