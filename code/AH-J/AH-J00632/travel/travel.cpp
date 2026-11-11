#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll a,b,s1,s2;
	char g1,g2;
	scanf("%lld %lld",&a,&s1);
	cin>>g1;
	scanf("%lld %lld",&b,&s2);
	cin>>g2;
	ll ok=1;
	if(a==b)	cout<<1;
	else{	
		cout<<0;
		ok=0;
	}
	if(ok==1&&s1==s2)	cout<<1;
	else{	
		cout<<0;
		ok=0;
	}
	if(ok==1&&((g1<='C'&&g2<='C')||(g1>'C'&&g2>'C')))	cout<<1;
	else{	
		cout<<0;
		ok=0;
	}
	if(ok==1&&abs(g1-g2)==1)	cout<<1;
	else{	
		cout<<0;
		ok=0;
	}
	return 0;
}

