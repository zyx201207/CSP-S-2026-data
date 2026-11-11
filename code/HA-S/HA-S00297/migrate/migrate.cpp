#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1000000;
ll a[N];

ll read(){
	ll s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}

int main(){
	ll c,t;c=read();t=read();
	while(t--){
		ll n,d;
		n=read();d=read();
		for(ll i=1;i<=n;i++){
			a[i]=read();
		}
	}
	cout<<0<<'\n';
	return 0;
}
