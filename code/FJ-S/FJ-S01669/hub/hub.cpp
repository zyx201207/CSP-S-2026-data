#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c=read(),t=read();
	while(t--){
		ll n=read(),k=read();
		for(int i=1;i<=n;i++){
			int u=read(),v=read();
		}
		if((n-k)%3==0) cout<<(n-k)/3<<"\n";
		else cout<<(n-k)/3+1<<"\n";
	}
	return 0;
}


