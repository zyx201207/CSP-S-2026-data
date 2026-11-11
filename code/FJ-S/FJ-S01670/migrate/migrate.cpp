#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const ll N=2e6+10;
ll c,_,n,d,x[N],ans;
namespace Mouz{
	ll f[N],g[N];
	ll q[N],head,tail;
	void solve(){
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++) f[j]=1e18;
			f[i]=0;
			g[i]=1;
			head=tail=1;
			q[head]=i;
			for (int j=i+1;j<=n;j++){
				while(head<=tail&&x[q[head]]<x[j]-d) head++;
				if(head>tail) break;
				f[j]=f[q[head]]+1;
				g[j]=g[q[head]];
				if(head+1<=tail&&f[q[head]]==f[q[head+1]]) {
					g[j]+=g[q[head+1]];
					if(head+2<=tail&&f[q[head+1]]==f[q[head+2]]) g[j]+=g[q[head+2]];
				}
				if(g[j]==2) ans++;
				q[++tail]=j;//似乎无论如何 f[j]>=f[q[tail]] ？ 
			}
		}
		printf("%lld\n",ans);
	}
}
namespace Navi{
	ll f[N],g[N],s[N];
	ll q[N],head,tail;
	void solve(){
		f[1]=0;
		g[1]=1;
		for (int i=2;i<=n;i++) f[i]=1e18;
		head=tail=1;
		q[head]=1;
		for (int j=2;j<=n;j++){
			s[j]=s[j-1];
			while(head<=tail&&x[q[head]]<x[j]-d) head++;
			if(head>tail) continue;
			f[j]=f[q[head]]+1;
			g[j]=g[q[head]];
			if(head+1<=tail&&f[q[head]]==f[q[head+1]]) {
				g[j]+=g[q[head+1]];
				if(head+2<=tail&&f[q[head+1]]==f[q[head+2]]) g[j]+=g[q[head+2]];
			}
			if(g[j]==2) s[j]++;
			q[++tail]=j;//似乎无论如何 f[j]>=f[q[tail]] ？ 
		}
		for (int i=1;i<=n;i++) ans+=s[n-i+1];
		printf("%lld\n",ans);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	_=read();
	while(_--){
		ans=0;
		n=read();
		d=read();
		for (int i=1;i<=n;i++) x[i]=read();
		if(c<=10) Mouz::solve();
		else if(c<=12) Navi::solve();
	}
}
/*
15:08开到了 T3？今年怎么这么水，比去年还水
希望记忆中的 弗洛伊德 没有写错
大样例过了就行了
15:19会了 O(n^2) 的做法，但似乎难以优化？
15:27欸等等，怎么是恰好两条？ 不能用bool了，直接记一个sum 
15:31OK，O(n^2)写完了
15:40OK，特殊性质A写完了
15:43等下再想，先看看T4 
*/
/*
1
5 3
-2 -1 0 1 2
*/
