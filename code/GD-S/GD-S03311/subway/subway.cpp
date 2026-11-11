#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
const long long inf=1e16;
long long w[M],f[N][N],t;
int s,a;
struct node{
	int u;
	long long cost;
};
vector<node> h[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&s);
//		a[i].resize(s+1),t[i].resize(s[i]+1); 
		for(int j=0;j<s;j++){
			scanf("%d%lld",&a,&t);
//			cout<<"a="<<a[i][j]<<" ";
//			cout<<"t="<<t[i][j]<<" ";
//			cout<<endl;
			h[a].push_back((node){i,t});
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			f[i][j]=inf;
		}
	}
//	cout<<"f="<<f[0][0]<<" ";
//	cout<<endl;
	for(int i=1;i<=m;i++){
		int siz=h[i].size();
//		cout<<"i="<<i<<" ";
//		cout<<"siz="<<siz<<" ";
//		cout<<endl;
		for(int j=0;j<siz;j++){
			for(int k=j+1;k<siz;k++){
				int u=h[i][j].u,v=h[i][k].u;
//				cout<<"j="<<j<<" ";
//				cout<<"k="<<k<<" ";
//				cout<<"u="<<u<<" ";
//				cout<<"v="<<v<<" ";
//				cout<<endl; 
				f[u][v]=f[v][u]=min(f[u][v],h[i][j].cost+h[i][k].cost);
			}
		}
	}
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<"i="<<i<<" ";
//			cout<<"j="<<j<<" ";
//			cout<<"f="<<f[i][j]<<" ";
//			cout<<endl; 
//		}
//	}
	int x,y;
	long long ans=0;
	while(q--){
		scanf("%d%d",&x,&y);
		ans=inf;
		for(auto i:h[x]){
			for(auto j:h[y]){
				ans=min(ans,i.cost+j.cost+f[i.u][j.u]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
} 
