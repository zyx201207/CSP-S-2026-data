#include<bits/stdc++.h>
using namespace std;
long long c,T,n,m,zzz,www,kkk,a[1000001],st[200001],h[200001];
inline long long read() {
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void bfs(long long x){
	memset(st,0x3f,sizeof st),memset(h,0,sizeof h);
	priority_queue<pair<long long,long long>>q;
	st[x]=0;
	q.push({0,x});
	while(q.size()){
		auto d=q.top();
		q.pop();
		for(long long i=d.second;i<=n;i++){
//			cout<<"1: "<<d.first<<" "<<d.second<<" "<<st[i]<<" "<<h[i]<<" "<<i<<endl;
			if(a[i]-a[d.second]>m)break;
			if(st[i]>1-d.first)st[i]=1-d.first,h[i]=0,q.push({-st[i],i});
			if(st[i]==1-d.first)h[i]++;
//			cout<<"2: "<<d.first<<" "<<d.second<<" "<<st[i]<<" "<<h[i]<<" "<<i<<endl;
		}
	}
	for(long long i=x;i<=n;i++)if(h[i]==2)www++;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--) {
		www=0,kkk=2;
		n=read(),m=read();
		for(long long i=1; i<=n; i++) {
			a[i]=read();
		}
//		if(c==13||c==14){
//			if(n!=4)cout
//		}
		for(long long i=1;i<=n;i++)bfs(i);
		cout<<www<<endl;
	}
	
	return 0;
}  /*
0 1
7 94
-40 92 168 183 266 407 436

0 1
9 67
55 192 207 255 299 303 327 457 602

8 98
8 72 132 203 349 416 557 600
*/
