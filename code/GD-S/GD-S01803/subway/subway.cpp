#include<bits/stdc++.h>
#define ll long long
#define pil pair<int,long long>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
ll in(){
	ll a=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) a=a*10+c-'0';
	return a*f;
}
operator <(pil a,pil b){
	return a.second<b.second;
}
operator >(pil a,pil b){
	return a.second>b.second;
}
int c,n,m,d,Q;
int w[500010];
int k[510];
vector<int>a[510],t[510];
vector<int>rt[500010];
priority_queue<pil,vector<pil>,greater<> >q;
ll f[500010];
vector<ll>L[500010];
int b[500010],l[500010],C;
int X[100010],Y[100010];
ll ans[100010];
bool cmp(pil a,pil b){
	return a<b;
}
int pre[500010];
vector<pii>wh[500010];
void work(int x,int y){
//	cout<<L[m][m]<<L[123].size();
	for(int i=1;i<=m;i++){
		f[i]=1e18;
		l[i]=0;
		b[i]=0;
	}
	f[x]=0;
	q.push(mp(x,0ll));
	while(!q.empty()){
		pil h=q.top();
		q.pop();
		int u=h.first;
		if(b[u]) continue;
		b[u]=1;
//		cout<<rt[u].size()<<'\n';
		if(!pre[u]){
			for(auto p:rt[u]){
				ll Lu;
				for(int i=0;i<k[p];i++){
					if(a[p][i]==u){
						Lu=t[p][i];
						break;
					}
				}
				for(int i=0;i<k[p];i++){
	//				cout<<a[p][i]<<'\n';
	//				cout<<u<<' '<<L[u].size()<<'\n';
//					if(L[u][a[p][i]]) 
						L[u][a[p][i]]=min(L[u][a[p][i]],t[p][i]+Lu);
//					else L[u][a[p][i]]=t[p][i]+Lu;
				}
			}
			pre[u]=1;
		}
		for(int v=1;v<=m;v++){
			if(f[v]>f[u]+L[u][v]){
				f[v]=f[u]+L[u][v];
				l[v]=u;
				if(!b[v]) q.push(mp(v,f[v]));
			}
		}
	}
	memset(b,0,sizeof(b));
	for(int i=y;i;i=l[i]){
//		cout<<'a'<<i<<'\n';
		b[i]=1;
	}
	for(int u=y;u;u=l[u]){
		for(auto j:wh[u]){
			int v=j.first,p=j.second;
			if(b[v]){
				if(ans[p]!=0) ans[p]=min(ans[p],abs(f[u]-f[v]));
				else ans[p]=abs(f[u]-f[v]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=in();n=in();m=in();d=in();Q=in();
	for(int i=1;i<=m;i++){
		w[i]=in();
		L[i].resize(m+10,1e18);
//		memset(L[i],0x3f,L[i]sizeof());
//		cout<<i<<' '<<L[i].size()<<'\n';
	}
	for(int i=1;i<=n;i++){
		k[i]=in();
		for(int j=1;j<=k[i];j++){
			a[i].push_back(in());
			t[i].push_back(in()); 
			rt[a[i][j-1]].push_back(i);
//			cout<<a[i][j-1]<<' '<<rt[a[i][j-1]][rt[a[i][j-1]].size()-1]<<'\n';
		}
	}
	for(int i=1;i<=Q;i++){
		X[i]=in();Y[i]=in();
		wh[X[i]].push_back(mp(Y[i],i));
		wh[Y[i]].push_back(mp(X[i],i));
	}
	int x,y;
//	printf("------------\n");
	for(int i=1;i<=Q;i++){
		x=X[i];y=Y[i];
		if(!ans[i]) work(x,y);
		printf("%lld\n",ans[i]+w[x]+w[y]);
	}
	return 0;
} 
