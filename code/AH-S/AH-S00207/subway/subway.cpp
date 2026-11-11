#include<bits/stdc++.h>
using namespace std;
const long long N=500005;
long long dsbc,n,m,dsbd,q,a[N];
long long e[505][505],w[505][505];
vector<long long> s[N],t[N];
void add(long long u,long long x,long long y){
	for(int i=0;i<int(s[x].size());i++){
		long long next=s[x][i],cost=t[x][i];
		e[u][next]=min(w[u][next],cost+y);
		e[next][u]=min(w[next][u],cost+y);
	}
}
void spfa(long long st){
	queue<long long> qu;
	long long aa[505];
	memset(aa,0x3f,sizeof(aa));
	qu.push(st);
	aa[st]=0;
	while(!qu.empty()){
		int now=qu.front();
		qu.pop();
		for(int i=1;i<=n;i++){
			if(e[now][i]==0x3f3f3f3f3f3f3f3f || e[now][i]==0) continue;
			if(aa[i]>aa[now]+e[now][i]){
				aa[i]=aa[now]+e[now][i];
				qu.push(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		w[st][i]=min(w[st][i],aa[i]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	memset(w,0x3f,sizeof(w));
	memset(e,0x3f,sizeof(e));
	cin>>dsbc>>n>>m>>dsbd>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1,k;i<=n;i++){
		e[i][i]=0;
		cin>>k;
		for(int j=1,x,y;j<=k;j++){
			cin>>x>>y;
			add(i,x,y);
			s[x].push_back(i);
			t[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++) spfa(i);
	for(int i=1,x,y;i<=q;i++){
		long long ans=0x3f3f3f3f3f3f3f3f;
		cin>>x>>y;
		for(int i=0;i<int(s[x].size());i++){
			for(int j=0;j<int(s[y].size());j++){
				ans=min(ans,w[s[x][i]][s[y][j]]+t[x][i]+t[y][j]);
			}
		}
		cout<<ans+a[x]+a[y]<<"\n";
	}
	return 0;
}




















