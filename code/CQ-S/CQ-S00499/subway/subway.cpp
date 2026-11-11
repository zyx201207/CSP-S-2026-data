#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,M=5e5+5;
int C,n,m,d,q,w[M];
ll a[N][N];
struct node{
	int x,v;
};
vector<node> t[N],id[M];
int read(){
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read();
		t[i].reserve(k);
		while(k--){
			int x=read(),v=read();
			t[i].push_back({x,v});
			id[x].push_back({i,v});
		}
		for(int j=1;j<=n;j++){
			if(i!=j)a[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		for(auto j:t[i]){
			for(auto k:id[j.x]){
				if(k.x==i)continue;
				a[i][k.x]=min(a[i][k.x],(ll)j.v+k.v);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	while(q--){
		int x=read(),y=read();
		ll ans=1e18;
		for(auto i:id[x]){
			for(auto j:id[y]){
				ans=min(ans,i.v+j.v+a[i.x][j.x]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	// cerr<<clock();
	return 0;
}