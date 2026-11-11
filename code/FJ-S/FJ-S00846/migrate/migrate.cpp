#include<cstdio>
#define N 2000005
using namespace std;

using ll=long long;
ll read() {
	ll x=0,t=1; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') t=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*t;
}
void write(ll x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
int T,n,fi[N],la[N],f[N][2],g[N];
ll ans,d,x[N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(),T=read();
	while(T--) {
		n=read(),d=read();
		for(int i=1;i<=n;i++) x[i]=read();
		for(int i=1,j=1;i<=n;i++) {
			while(j<n&&x[j+1]-x[i]<=d) j++;
			la[i]=j;
		}
		for(int i=1,j=1;i<=n;i++) {
			while(x[i]-x[j]>d) j++;
			fi[i]=j;
		}
		for(int i=1;i<=n;i++) f[i][0]=f[i][1]=g[i]=0;
		
		// f[i][0/1] 表示以 i 结尾，上一个是 first[i] 还是起点  
		// g[i] 表示以 i 结尾，之前有过 x=first[y]+1 的 x->y 
		
		ans=0;
		for(int i=1;i<=n;i++) {
			if(fi[i]<i) {
				ans+=g[fi[i]];
				if(la[fi[i]]==i) f[i][0]+=f[fi[i]][0]+f[fi[i]][1],g[i]+=g[fi[i]];
			}
			if(fi[i]+1<i) {
				ans+=f[fi[i]+1][1];
				if(la[fi[i]+1]==i) g[i]+=f[fi[i]+1][1];
				
				if(fi[fi[i]+1]==fi[fi[i]]) {
					ans+=f[fi[i]+1][0];
					if(la[fi[i]+1]==i) g[i]+=f[fi[i]+1][0];
				}
			}
			if(la[i]>i) {
				f[la[i]][1]++;
			}
		}
		write(ans),putchar('\n');
	}
	return 0;
}

/*
check if <vector> <cmath> is open

check long long

dp, f[x] 表示路径以 x 结尾 的起点数量 
增加 0/1 表示之前是否有 x=first[y]+1，若有，则以后只能 x=first[y] 
每次转移 x=first[y]+(0/1)，且 last[x]=y 
first,last -> two-pointer
时间复杂度 O(n) 

初值把 last[i] +1 
统计答案时只有 g[first[i]] 和 f[first[i]+1] 是有用的 

y 也要记，x=first[i]+1 时，需满足 y=first[first[i]]
y 至多只有 2 种：
f: 0/1 表示 y=first[x]，起点 

16:27
*/
