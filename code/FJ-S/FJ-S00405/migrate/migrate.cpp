#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll read(){
	ll ans=0,w=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-'){
			w=-w;
		}
		s=getchar();
	}
	while(isdigit(s)){
		ans=(ans<<3LL)+(ans<<1LL)+(s^48);
		s=getchar(); 
	}
	return ans*w;
}

const int N=2e6+10;
ll x[N];
ll pre[N],suf[N];
ll n,d;
ll vis[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c=read(),t=read();
	while(t--){
		init();
		n=read(),d=read();
		if(n<=3){
			puts("0");
			continue;
		}
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		
		int l=1;
		for(int i=1;i<=n;i++){
			while(l<i && a[i]-a[l]>d){
				l++;
			}
			pre[i]=l;
		}
		int r=n;
		for(int i=n;i>=1;i--){
			while(i<r && a[r]-a[i]>d){
				r--;
			}
			suf[i]=r;
		}
		
		for(int i=1;i<=n;i++){
			vis[pre[i]]++;
		}
		
		for(int i=1;i<=n;i++){
			
		}
	}
	
	return 0;
}
