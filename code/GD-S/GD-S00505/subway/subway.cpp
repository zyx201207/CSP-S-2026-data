#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int sum=0,f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=(sum<<3)+(sum<<1)+ch-'0';
		ch=getchar();
	}
	return sum*f;
}
int testid,n,m,d,Q;
vector<pair<int,int> >ways[500005];
int ct[500005];
int f[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	testid=read();
	n=read();
	m=read();
	d=read();
	Q=read();
	for(int i=1;i<=m;++i){
		ct[i]=read();
	}
	for(int i=1;i<=n;++i){
		int k=read();
		for(int j=1;j<=k;++j){
			int np=read(),t=read();
			ways[np].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;++i)f[i][i]=0;
	for(int i=1;i<=m;++i){
		for(auto x=ways[i].begin();x!=ways[i].end();x++){
			for(auto y=x+1;y!=ways[i].end();y++){
				int a=(*x).first,b=(*y).first,t=(*x).second+(*y).second;
				f[a][b]=f[b][a]=min(f[a][b],t);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int tagid=1;tagid<=Q;++tagid){
		int S=read(),T;
		T=read();
		int ans=0x3f3f3f3f3f3f3f3f;
		for(auto x:ways[S]){
			for(auto y:ways[T]){
				ans=min(ans,f[x.first][y.first]+x.second+y.second);
			}
		}
		printf("%lld\n",ans+ct[S]+ct[T]); 
		
	}
}

