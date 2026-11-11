#include<bits/stdc++.h>
#define qwe(i,l,r) for(int i=(l);(i)<=(r);++i)
#define ewq(i,l,r) for(int i=(l);(i)>=(r);--i)
#define qwex(e,x) for(int e=(x);e;e=ne[e])
#define ll long long
#define int ll
#define pii pair<int,int>
#define fir first
#define sec second
#define low(x) (x)&(-(x))
#define whlie while
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		f=ch=='-'?-f:f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
const int N=2e6+5;
int n,m,a[N],cc;
int g[N];
void solve1(){
	int ans=0;
	qwe(l,1,n){
		g[l]=1;
		int x=l,y=l,sum=1;
		qwe(i,l+1,n){
			if(a[i]-a[i-1]>m)break;
			while(x<=y&&a[i]-a[x]>m)sum-=g[x++];
			if(x>y){
				y=i-1;sum=0;
				qwe(j,x,y)sum+=g[j];
				--i;continue;
			}
			else g[i]=sum;
			if(g[i]==2)++ans;
		}
	}
	cout<<ans<<'\n';
}
void solve2(){
	int ans=0;
	g[1]=1;
	int x=1,y=1,sum=1;
	qwe(i,2,n){
		if(a[i]-a[i-1]>m)break;
		while(x<=y&&a[i]-a[x]>m)sum-=g[x++];
		if(x>y){
			y=i-1;sum=0;
			qwe(j,x,y)sum+=g[j];
			--i;continue;
		}
		else g[i]=sum;
		if(g[i]==2)ans+=n-i+1;
	}
	cout<<ans<<'\n';
}
void solve3(){
	puts("0");
}
void solve(){
	n=read();m=read();
	qwe(i,1,n)a[i]=read();
	if(cc<=10){
		solve1();
		return;
	}
//	bool op=1;
//	qwe(i,3,n)if(a[i]-a[i-1]!=a[2]-a[1]){
//		op=0;
//		break;
//	}
	if(cc<=12){
		solve2();
		return;
	}
	solve3();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cc=read();
	int T=read();
	while(T--)solve();
}
