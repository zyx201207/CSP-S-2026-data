#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b,c,d;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	bool p=0;
	if(a==c){
		 cout<<1;
		 p=1;
	}else cout<<0;
	
	string b1="";
	b1+=b[0];
	b1+=b[1];
	string d1="";
	d1+=d[0];
	d1+=d[1];
	bool q=0;
	
	if(b1==d1&&p){
		 cout<<1;
		 q=1;
	}else cout<<0;
	char b2=b[2];
	char d2=d[2];
	bool f=0;
	
	if(b2>='A'&&b2<='C'&&d2>='A'&&d2<='C'&&q){
		 cout<<1;
		 f=1;
	}else if(b2>='D'&&b2<='F'&&d2>='D'&&d2<='F'&&q){
		 cout<<1;
		 f=1;
	}else cout<<0;
	
	if(abs(b2-d2)==1&&f) cout<<1;
	else cout<<0;
	return 0;
}
