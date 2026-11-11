#include <bits/stdc++.h>
using namespace std;
template <typename type>
void read(type &val){
	val=0;
	char ch=getchar();
	while(ch<'0'||'9'<ch)
		ch=getchar();
	while('0'<=ch&&ch<='9'){
		val=val*10+(ch-'0');
		ch=getchar();
	}
}
template <typename type>
void write(type val){
	int top=0;
	static char __dights[32];
	do{
		__dights[++top]=val%10+'0';
		val/=10;
	}while(val);
	while(top)
		putchar(__dights[top--]);
}
using ll=long long;
const int maxN=5e5,maxM=500;
const ll inf=(1ll<<60);
int n,m,q,w[maxN+5];
ll d[maxM+5][maxM+5];
vector<array<int,2>> sub[maxN+5];
void solve(){
	read(m),read(n),read(q),read(q);
	for(int i=1;i<=n;i++)
		read(w[i]);
	for(int i=1;i<=m;i++){
		int siz;
		read(siz);
		for(int j=1;j<=siz;j++){
			int id,tim;
			read(id),read(tim);
			sub[id].push_back({i,tim});
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			d[i][j]=inf;
	for(int i=1;i<=m;i++)
		d[i][i]=0;
	for(int k=1;k<=n;k++){
		int siz=(int)sub[k].size();
		for(int i=0;i<siz;i++)
			for(int j=i+1;j<siz;j++){
				ll s=sub[k][i][1]+sub[k][j][1];
				int u=sub[k][i][0],v=sub[k][j][0];
//				printf("From Subway %d to Subway %d by Station %d, Time: %lld\n",u,v,k,s);
				d[u][v]=min(d[u][v],s);
				d[v][u]=min(d[v][u],s);
			}
	}
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(int u,v;q;q--){
		read(u),read(v);
		ll ans=inf;
		int su=(int)sub[u].size(),sv=(int)sub[v].size();
		for(int i=0;i<su;i++)
			for(int j=0;j<sv;j++){
				ll s=sub[u][i][1]+sub[v][j][1];
				int p=sub[u][i][0],q=sub[v][j][0];
				ans=min(ans,d[p][q]+s);
			}
		write(ans+w[u]+w[v]);
		putchar(10);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
	scanf("%d",&T);
	for(T=1;T;T--) solve();
}
