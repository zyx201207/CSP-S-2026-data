#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,x[N],ans[N],cnt[N],res,n,d;
long long read() {
	long long k=0,f=1,c=getchar();
	for(; !isdigit(c); c=getchar()) if(c=='-') f=-1;
	for(; isdigit(c); c=getchar()) k=k*10+c-'0';
	return k*f;
}
struct Node{
	long long id,val;
};
long long bfs(long long s) {
	memset(ans,0x3f3f3f3f3f3f3f3f,sizeof(ans));
	memset(cnt,0,sizeof(cnt));
	long long aans=0;
	queue<Node>q;
	q.push({s,0});
	while(!q.empty()) {
		long long h=q.front().id,w=q.front().val;
		q.pop();
		for(int i=h+1; i<=n; i++) {
			if(x[i]-x[h]<=d) {
				if(ans[i]>w+1) {
					q.push({i,w+1});
					ans[i]=w+1;
					cnt[i]=1;
				}
				else if(ans[i]==w+1){
					q.push({i,w+1});
					cnt[i]++;
				}
			}
			else break;
		}
	}
	for(int i=s;i<=n;i++) if(cnt[i]==2) aans++;
	return aans;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--) {
		n=read(),d=read();
		res=0;
		for(int i=1; i<=n; i++) x[i]=read();
		for(int i=1; i<=n; i++) res+=bfs(i);
		printf("%lld\n",res);
	}
	return 0;
}
