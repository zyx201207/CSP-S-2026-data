#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;
const int N=5e5+5;
int n;
ll m;
ll a[N];

inline ll read(){
	ll x=0;
	int f=1;
	char c=getchar();
	while(c<48||c>57){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>=48&&c<=57){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return f==-1?-x:x;
}

void solve(){
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	ll s=0;
	int ans=0;
	for(int i=1,j=1;i<=n;i++){
		s+=a[i];
		while(1ll*(i-j+1)*a[i]-s>m) s-=a[j++];
		ans=max(ans,i-j+1);
	}
	printf("%d",ans);
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int o,T=1;
	while(T--) solve();
	return 0;
}
