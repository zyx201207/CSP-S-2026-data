#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=540,M=5e5+20,INF=0x3f3f3f3f3f3f3f3f;
ll n,m,d,q,mi[N][N],x,y,ans[N][N];
int a[M];
struct node{
	ll a,t;
};
struct node1{
	ll to,a;
};
vector<node>b[N],c[M];
vector<node1>e[N];
ll find(ll fr,ll to){
	ll sum=INF;
	for(int i=0;i<c[fr].size();i++){
		for(int j=0;j<c[to].size();j++){
			sum=min(sum,mi[c[fr][i].a][c[to][j].a]+c[to][j].t+c[fr][i].t);
		}
	}
	return sum;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c1;
	memset(mi,INF,sizeof(mi));
	scanf("%lld%lld%lld%lld%lld",&c1,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			node d;
			scanf("%lld%lld",&d.a,&d.t);
			b[i].push_back(d);
			for(int k1=0;k1<c[d.a].size();k1++){
				mi[i][c[d.a][k1].a]=min(mi[i][c[d.a][k1].a],d.t+c[d.a][k1].t);
				mi[c[d.a][k1].a][i]=mi[i][c[d.a][k1].a];
			}
			c[d.a].push_back({i,d.t});
		}
	}
	for(int i=1;i<=n;i++){
		mi[i][i]=0;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=j;k++){
				if(i==j)break;
				if(j==k||i==k)continue;
				mi[i][j]=min(mi[i][j],mi[i][k]+mi[k][j]);
				mi[j][i]=mi[i][j];
			}
		}
	}
	while(q--){
		scanf("%lld%lld",&x,&y);
		ll ans1=a[x]+a[y];
		ans1+=find(x,y);
		printf("%lld\n",ans1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
