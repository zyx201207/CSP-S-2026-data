#include<iostream>
#include<string>
using namespace std;

struct sec{
	char c;
	long long len;
};

const int MAXN=2e5+5;

sec s[MAXN];

int gcd(int a,int b){
	return a%b==0?b:gcd(b,a%b);
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0,g=1;
	long long ans=0,lpos=0,rpos=0,e=0;
	sec *ls,*rs;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].len>>s[i].c;
		if(i==2) g=gcd(s[i].len,s[i-1].len);
		else g=gcd(g,s[i].len);
	}
	for(int i=1;i<=n;i++){
		s[i].len/=g;
		e+=s[i].len;
	}
//	cout<<(e%2==0);
	ls=s;
	rs=s+n;
//	cout<<rs->c;
	e/=2;
	while(lpos<e){
		if(lpos>=ls->len){
			lpos-=ls->len;
			e-=ls->len;
			ls++;
		}if(rpos>=rs->len){
			rpos-=rs->len;
			rs--;
		}
		if(ls->c!=rs->c) ans++;
		lpos++;
		rpos++;
	}
	cout<<ans*g;
	return 0;
}
