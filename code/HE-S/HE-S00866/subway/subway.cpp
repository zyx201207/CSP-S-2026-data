#include <bits/stdc++.h>
using namespace std;
const int M=5e5+5;
const long long INF=1e18;
int c,n,m,d,q,x;
long long w[M];
long long h[501][M];
int k[501];
vector<int> a[501];
vector<long long> t[501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
		h[1][i]=INF;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=2*k[i];j++){
			scanf("%d",&x);
			if(j&1) a[i].push_back(x);
			else t[i].push_back(x);
		}
	}
	for(int i=0;i<k[1];i++)	h[1][a[1][i]]=t[1][i];
	long long mn;
	for(int i=2;i<=n;i++){
		for(int o=1;o<=i-1;o++){
			mn=INF;
			for(int j=0;j<k[i];j++){
				int pos=a[i][j],val=t[i][j];
				mn=min(mn,h[o][pos]+val);
			}
			for(int j=0;j<k[i];j++){
				int pos=a[i][j],val=t[i][j];
				h[o][pos]=min(h[o][pos],val+mn);
			}
		}
		for(int j=1;j<=m;j++) h[i][j]=INF;
		for(int j=0;j<k[i];j++) h[i][a[i][j]]=t[i][j];
	}
	long long ans;
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ans=INF;
		for(int i=1;i<=n;i++) ans=min(ans,h[i][x]+h[i][y]);
		printf("%lld\n",w[x]+w[y]+ans);
	}
}
