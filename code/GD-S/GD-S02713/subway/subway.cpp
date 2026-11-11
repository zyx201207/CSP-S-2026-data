#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+10;
struct tt{
	int x,s;
};
vector<tt> a[505];
int d[5005][5005];
int n,c,m,dd,q;
int w[MAXN],k[MAXN],l[MAXN],r[MAXN],ans[MAXN];
main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=500;i++)
	for(int j=1;j<=500;j++) d[i][j]=1e18;
	scanf("%lld%lld%lld%lld%lld",&c,&m,&n,&dd,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int i=1;i<=m;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			a[i].push_back({x,y});
		}
		for(int j=0;j<a[i].size();j++){
			for(int k=0;k<a[i].size();k++){
				int x=a[i][j].x,y=a[i][k].x,s=a[i][j].s+a[i][k].s;
				if(x==y) continue;
				d[x][y]=min(d[x][y],s);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		ans[i]=d[x][y]+w[x]+w[y];
	}
	for(int i=1;i<=q;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
} 
