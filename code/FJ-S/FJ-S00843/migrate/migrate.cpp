#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3000010;
inline ll read(){
	ll x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') y=-y;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*y;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
ll n,K;
ll a[N],ne[N];
ll f[N],g[N],h[N];

ll ans;

void solve(){
	n=read(),K=read();ans=0;
	for(int i=1;i<=n;i++) a[i]=read(),f[i]=g[i]=h[i]=0;
	ll R=n;
	for(int i=n;i>=1;i--){
		while(a[R]-a[i]>K&&R>=0) R--;
		ne[i]=R;
	}
	
	R=n;
	for(int i=n;i>=1;i--){
		if(ne[i]==i){R=i;continue;}
		else if(ne[i]==R){continue;}
		else if(ne[ne[i]]==R){
			f[i]=R-ne[ne[i]-1];
			h[i]=ne[ne[i]-1]-max(ne[ne[i]-2],ne[i]);
		}
		else{
			if(ne[i]==i+1){
				f[i]=f[ne[i]]+ne[ne[i]]-ne[i];
				g[i]=g[ne[i]]+h[ne[i]];
				h[i]=0;
			}
			else if(ne[i]==i+2){
				if(ne[ne[i]-1]==ne[ne[i]]){
					h[i]+=f[ne[i]]+ne[ne[i]]-ne[i];
				}
				else{
					if(ne[ne[i]-1]<ne[ne[i]]-1) g[i]+=h[ne[i]];
					f[i]+=f[ne[i]],g[i]+=g[ne[i]];
					
					f[i]+=ne[ne[i]]-ne[ne[i]-1];
					h[i]+=ne[ne[i]-1]-ne[i];
				}
			}
			else{
				if(ne[ne[i]-2]==ne[ne[i]]) f[i]=g[i]=h[i]=0;
				else if(ne[ne[i]-1]==ne[ne[i]]){
					h[i]+=f[ne[i]]+ne[ne[i]-1]-ne[ne[i]-2];
				}
				else{
					if(ne[ne[i]-1]<ne[ne[i]]-1) g[i]+=h[ne[i]];
					f[i]+=f[ne[i]],g[i]+=g[ne[i]];
					
					f[i]+=ne[ne[i]]-ne[ne[i]-1];
					h[i]+=ne[ne[i]-1]-ne[ne[i]-2];
				}
			}
		}
	}
	for(int i=1;i<=n;i++) ans+=g[i]+h[i];
	write(ans),putchar('\n');
}
		

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read();ll T=read();
	while(T--) solve();
	return 0;
}
