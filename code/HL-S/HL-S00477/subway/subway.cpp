#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qq;
long long ans;
const int N=5e5+100;
long long a[N];
struct edge{
	long long data;
	int v;
	int nex;
}e[N<<2];
int head[N];
long long cnt;
void add(int u,int v,long long data) {
	e[++cnt].v=u;
	e[cnt].data=data;
	e[cnt].nex=head[v];
	head[v]=cnt;
}
int b[N];
long long t[N];
int xi,yi;
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&qq);
	for(int i=1;i<=m;i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++) {
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++) {
			scanf("%d%d",&b[j],&t[j]);
		}
		for(int j=1;j<=k;j++) {
			for(int l=j+1;l<=k;l++) {
				add(b[j],b[l],t[j]+t[l]);
				add(b[l],b[j],t[j]+t[l]);
//				printf("%d %d\n",b[j],b[l]);
			}
		}
	}
//	printf("%d",cnt);
//	for(int j=1;j<=m;j++) for(int i=head[j];i!=0;i=e[i].nex) {
//		printf("%d %d %d\n",j,e[i].v,e[i].data);
//	}
	while(qq--) {
		ans=0x7FFFFFFF;
		scanf("%d%d",&xi,&yi);
		stack<pair<int,pair<int,long long> > > q;
		q.push(make_pair(-1,make_pair(xi,0)));
		while(!q.empty()) {
		pair<int,pair<int,long long> > tmp=q.top();
		q.pop();
		if(tmp.second.first==yi) {
			ans=min(ans,tmp.second.second);
			continue;
		}
		for(int i=head[tmp.second.first];i!=0;i=e[i].nex) {
			if(e[i].data+tmp.second.second>ans || tmp.first==e[i].v) continue;
			else q.push(make_pair(tmp.second.first,make_pair(e[i].v,e[i].data+tmp.second.second)));
			if(q.top().second.first==yi) {
				ans=min(ans,q.top().second.second);
				q.pop();
			}
			}
		}
		printf("%lld\n",ans+a[xi]+a[yi]);
	}
	return 0;
}
