#include<bits/stdc++.h>
using namespace std;
#define ll long long

inline int read(){
	int a=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		a=(a<<3)+(a<<1)+(ch-'0');
		ch=getchar();
	}
	return a*f;
}
inline void write(int a){
	if (a<0){
		a=-a;
		putchar('-');
	}
	if (a>=10) write(a/10);
	putchar(a%10+'0');
}
const int N=500;
int c,T,n,d,li[N],f[N][N][N],ans,jl[N],s[N];
struct node{
	int w,len;
};
void bfs(int x){
	queue<node> q;
	q.push({x,0});
	memset(jl,0x3f,sizeof(jl));
	memset(s,0,sizeof(s));
	while (q.size()){
		node h=q.front();
		q.pop();
		if (jl[h.w]<h.len) continue;
		if (jl[h.w]>=h.len){
			jl[h.w]=h.len;
			s[h.w]++;
		}
		for (int i=h.w+1;i<=n;i++){
			if (li[i]-li[h.w]<=d){
				q.push({i,h.len+1});
			}
			else break;
		}
	}
	for (int i=x+1;i<=n;i++){
		if (s[i]==2){
			ans++;
//			cout<<x<<' '<<i<<'\n';
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();T=read();
	while (T--){
		n=read();d=read();
		for (int i=1;i<=n;i++){
			li[i]=read();
		}
		int p=li[2]-li[1];
		bool t=true;
		for (int i=3;i<=n;i++){
			if (li[i]-li[i-1]!=p) t=false; 
		}
//		if (t){
//			if (li[1]+d>=li[n]||li[3]-li[1]>d) write(0);
//			else write(n-3);
//			putchar('\n');
//			continue;
//		}
		for (int i=1;i<=n;i++){
			bfs(i);
		}
		write(ans);putchar('\n');
		ans=0;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
15 6
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

0 1
15 6
2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

0 1
10 5
1 3 5 7 9 11 13 15 17 19

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
