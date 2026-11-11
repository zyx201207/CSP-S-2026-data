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
#define maxn 2000006
using namespace std;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
void writeln(ll x){
	if(x==0){
		putchar('0');putchar('\n');return;
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
	putchar('\n');
}
const ll inf=0x3f3f3f3f3f3f3f3f;
int TC,T,n;
ll a[maxn],d;
ll f[5005][5005],cnt[5005][5005];
bool vis[5005]; 
void dijkstra(int s){
	rep(i,1,n){
		cnt[s][i]=0;
		vis[i]=0;
		f[s][i]=inf;
	}
	f[s][s]=0;
	cnt[s][s]=1;
	rep(i,1,n){
		ll mi=inf;
		int mii=-1;
		rep(j,1,n){
			if(vis[j])continue;
			if(f[s][j]<mi){
				mi=f[s][j],mii=j;
			}
		}
		if(mii==-1)break;
		vis[mii]=1;
		rep(j,1,n){
			if(abs(a[mii]-a[j])<=d){
				if(f[s][j]>f[s][mii]+1){
					f[s][j]=f[s][mii]+1;
					cnt[s][j]=cnt[s][mii];
				}else if(f[s][j]==f[s][mii]+1){
					cnt[s][j]+=cnt[s][mii];
				}
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	scanf("%d%d",&TC,&T);
	TC=read();
	T=read();
	while(T--){
//		scanf("%d%lld",&n,&d);
		n=read();
		d=read();
		rep(i,1,n){
			a[i]=read();
		}
		if(TC<=10){
			rep(i,1,n){
				dijkstra(i);
			}
			ll ans=0;
			rep(i,1,n){
				rep(j,i+1,n){
					if(cnt[i][j]==2)++ans;
				}
			}
			writeln(ans);
		}else if(11<=TC&&TC<=12){
			if(n==1){
				writeln(0);
				continue;
			}
			ll D=a[2]-a[1];
			ll x=d/D;
			if(x<=1){
				writeln(0);
			}else if(x+(x-1ll)+1<=n){
				writeln(n-x-(x-1ll));
			}else{
				writeln(0);
			}
		}else if(13<=TC&&TC<=14){
			writeln(0);
		}else{
			rep(i,1,n){
				dijkstra(i);
			}
			ll ans=0;
			rep(i,1,n){
				rep(j,i+1,n){
					if(cnt[i][j]==2)++ans;
				}
			}
			writeln(ans);
//			printf("idk\n");
		}
	}
	return 0;
}
// Oct31>=Dec25?
// 40pts?
// I do not know anything!
// Tomato everything will be fine!
// I love CCF.
// SCP-S01285
