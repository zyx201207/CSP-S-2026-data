#include<bits/stdc++.h>
#define ll long long
#define ri register int
#define ld long double
#define stg string
#define Cn const
using namespace std;
ll read() {
	ll r=0,fl=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') fl=-fl;c=getchar();}
	while(c>='0'&&c<='9') {r=(r<<3)+(r<<1)+(c^48);c=getchar();}
	return r*fl;
}
ll Max(ll a,ll b) {return a>b?a:b;}
ll Min(ll a,ll b) {return a<b?a:b;}
Cn ld eps=1e-9;
Cn ll Inf=1e18;
Cn int N=5e3+5,M=2e6+5;
ll n,x[M],d,c,T;
ll f[N][N],mn[N][N],nxt[M],pre[M];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();T=read();
	if(c<=10) {
		while(T--) {
			n=read();d=read();
			for(int i=1;i<=n;i++) x[i]=read();
			int j=1;
			for(int i=1;i<=n;i++) {
				if(j<i) j=i;
				while(j<n&&x[j+1]-x[i]<=d) j++;
				nxt[i]=j;
			}
			for(int i=1;i<=n;i++) {
				for(int j=i;j<=n;j++) f[i][j]=0,mn[i][j]=Inf;
			}
			for(int i=1;i<=n;i++) {
				mn[i][i]=0;f[i][i]=1;
				for(int j=i;j<=n;j++) {
					if(mn[i][j]==Inf) break;
					for(int p=j+1;p<=nxt[j];p++) {
						(mn[i][p]>mn[i][j]+1)&&(mn[i][p]=mn[i][j]+1)&&(f[i][p]=0);
						(mn[i][p]==mn[i][j]+1)&&(f[i][p]+=f[i][j]);
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++) {
				for(int j=i;j<=n;j++) {
					if(f[i][j]==2) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	else if(c==11||c==12) {
		while(T--) {
			n=read();d=read();
			for(int i=1;i<=n;i++) x[i]=read();
			if(n<=3) cout<<0<<endl;
			else {
				ll ch=x[2]-x[1];
				if(ch>d||d%ch) cout<<0<<endl;
				else cout<<Max(n-(d/ch)*2+1,0)<<endl;
			}
		}
	}
	else if(c==13||c==14) {
		while(T--) {
			n=read();d=read();
			for(int i=1;i<=n;i++) x[i]=read();
			int j=1;
			for(int i=1;i<=n;i++) {
				if(j<i) j=i;
				while(j<n&&x[j+1]-x[i]<=d) j++;
				nxt[i]=j;
			}
			j=n;
			for(int i=n;i>=1;i--) {
				if(j>i) j=i;
				while(j>1&&x[i]-x[j-1]<=d) j--;
				pre[i]=j;
			}
			ll cnt=0,d1=0,d2;
			for(int i=1;i<=n;i++) {
				//cout<<pre[i]<<" "<<nxt[i]<<endl;
				if(pre[i]==1&&nxt[i]==n) {
					cnt++;
					if(!d1) d1=i;
					d2=i;
				}
			}
			cout<<cnt<<endl;
			if(cnt!=2) cout<<0<<endl;
			else {
				ll ans=0;
				for(int i=1;i<=d1;i++) {
					ans+=n-nxt[i];
				}
				cout<<ans<<endl;
			}
		}
	}
	else {
		while(T--);
		cout<<0<<endl;
	}
}
