// Thanks for judging my code!
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define down(i,x,y) for(int i=(x);i>=(y);--i)
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
#define eb emplace_back
#define pb push_back
#define maxm 500005
#define maxn 505
#define pil pair<int,ll>
using namespace std;
int TC,n,m,d,Q;
ll a[maxm];
pil g[maxm][22];
int ccnt[maxm];
ll f[maxn][maxn];
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
void write(ll x){
	if(x==0){
		putchar(48);return;
	}
	if(x<0){
		putchar('-');x=-x;
	}
	static char STA[67];
	static int TOP=0;
	while(x){
		STA[++TOP]=x%10+48;
		x/=10;
	}
	while(TOP){
		putchar(STA[TOP]);
		--TOP;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	TC=read();
	n=read();
	m=read();
	d=read();
	Q=read();
	rep(i,1,m){
		a[i]=read();
	}
	rep(i,1,n){
		int L=read();
		rep(j,1,L){
			int x=read();
			ll t=read();
			g[x][++ccnt[x]]=mkp(i,t);
		}
	}
	rep(i,1,n){
		rep(j,1,n){
			f[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	rep(i,1,n)f[i][i]=0;
	rep(i,1,m){
		rep(j,1,ccnt[i]-1){
			rep(k,j+1,ccnt[i]){
				f[g[i][j].fi][g[i][k].fi]=min(f[g[i][j].fi][g[i][k].fi],g[i][j].se+g[i][k].se);
//				f[g[i][k].fi][g[i][j].fi]=min(f[g[i][k].fi][g[i][j].fi],g[i][j].se+g[i][k].se);
			}
		}
	}
	rep(i,1,n){
		rep(j,1,n){
			f[i][j]=min(f[i][j],f[j][i]);
		}
	}
	rep(k,1,n){
		rep(i,1,n){
			rep(j,1,n){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(Q--){
		int x=read();
		int y=read();
		ll ans=1e18;
		rep(I,1,ccnt[x]){
			rep(J,1,ccnt[y]){
				pil p=g[x][I],q=g[y][J];
				ans=min(ans,a[x]+a[y]+p.se+q.se+f[p.fi][q.fi]);
			}
		}
		write(ans);putchar('\n');
	}
	return 0;
}
// DO NOT OPEN THIS FILE!
// Secure. Contain. Protect
// Oct31!=Dec25!
// Tomato everything may be fine!
// Good Luck!
// Accepted!
// Accepted!
// Accepted!
// 68~100pts
/*
sto sto sto %%% Judge Machine %%% orz orz orz
sto sto sto %%%     Data      %%% orz orz orz
O(md^2+n^3+Qd^2)
~3.65*10^8
Time Limit:1s
Survive!
I love CCF.
*/
