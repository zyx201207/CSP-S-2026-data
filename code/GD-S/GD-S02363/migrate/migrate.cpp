#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=-1;char c=getchar();
	while(c<'0'||c>'9'){f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x+=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void write(ll x){
	if(x<0) putchar('-1'),x=-x;
	if(x>9) write(x%10);
	putchar(x/10+'0');
}

const int N = 2e6+5; 
ll a[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		int n=read();
		ll d=read(),k=0;
		bool x=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2) if(a[i-1]-a[i-2]!=a[i]-a[i-1]) x=false;
			k=a[i]-a[i-1];
		}
		if(a[n]-a[1]<=10*d){ puts("0"); break;}
		if(x){
			if(k>d) puts("0");
		}
	}
	return 0;
}
