#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2e6+1,Inf=0x3f3f3f3f3f3f3f3f;
__inline void read(int&x){
	char ch=getchar();
	int fl=1;
	x=0;
	while(!isdigit(ch)){
		if(ch=='-')
			fl=-1;
		ch=getchar();
	}
	while(isdigit(ch))
		x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x*=fl;
	return;
}
__inline void write(int x){
	if(x>=10){
		write(x/10);
		x%=10;
	}
	putchar(x^48);
	return;
}
__inline void writeln(int x){
	write(x);
	putchar('\n');
	return;
}
int Id,T,n,d,a[N],pre[N],nxt[N],f[N],g[N],ans;
void clear(){
	ans=0;
	return;
}
void task(){
	clear();
	read(n),read(d);
	for(int i=1;i<=n;i++)
		read(a[i]);
	for(int i=1,j=1;i<=n;i++){
		while(j<n&&a[j+1]-a[i]<=d)
			j++;
		nxt[i]=j;
	}
	for(int i=n,j=n;i>=1;i--){
		while(j>1&&a[i]-a[j-1]<=d)
			j--;
		pre[i]=j;
	}
	for(int i=1;i<=n;i++){
		f[i]=1;
		if(pre[i]==i)
			continue;
		f[i]+=pre[i+1]-pre[i]-1;
		if(nxt[pre[i]]==i)
			f[i]+=f[pre[i]];
		else
			f[i]++;
	}
	for(int i=n;i>=1;i--){
		g[i]=1;
		if(nxt[i]==i)
			continue;
		g[i]+=nxt[i]-nxt[i-1]-1;
		if(pre[nxt[i]]==i)
			g[i]+=g[nxt[i]];
		else
			g[i]++;
	}
	for(int u=1,v=2,li,ri,lj,rj,icnt,jcnt,fli,flj;v<=n;u++,v++){
		li=pre[v],ri=min(pre[v+1],u)-1,lj=max(nxt[u-1],v)+1,rj=nxt[u];
		if(nxt[u]<v||u<pre[v]||li>ri||lj>rj)
			continue;
		fli=(li<=pre[u]&&pre[u]<=ri),flj=(lj<=nxt[v]&&nxt[v]<=rj);
		icnt=(ri-li+1-fli)+fli*f[pre[u]],jcnt=(rj-lj+1-flj)+flj*g[nxt[v]];
		ans+=icnt*jcnt;
	}
	return writeln(ans);
}
string program(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(0);
	for(read(Id),read(T);T;T--)
		task();
	return"H17"; 
}
string H17=program();
signed main(){
	return 0;
}
