#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,k;
};
const long long INF=0x3f3f3f3f3f3f3f3f;
long long c,n,m,d,q;
long long w[500001];
long long ans[501][501];
vector<node> a[500001];
long long p[501][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(ans,0x3f,sizeof ans);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	long long k,x;
	for(long long i=1;i<=n;i++)ans[i][i]=0;
	for(long long i=1;i<=n;i++){
		cin>>k;
		for(long long j=1;j<=k;j++){
			cin>>x>>p[i][j];
			for(node ij:a[x]){
				ans[ij.k][i]=ans[i][ij.k]=min(ans[i][ij.k],p[i][j]+p[ij.k][ij.x]);
			}
			a[x].push_back({j,i});
		}
	}
	for(k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(ans[i][k]!=INF&&ans[k][j]!=INF){
					ans[j][i]=ans[i][j]=min(ans[i][k]+ans[k][j],ans[i][j]);
				}
			}
		}
	}
	long long y;
	long long cnt=0;
	while(q--){
		cnt=0;
		cin>>x>>y;
		for(node i:a[x]){
			for(node j:a[y]){
				if(cnt==0){
					cnt=p[i.k][i.x]+p[j.k][j.x]+ans[i.k][j.k];
				}else{
					cnt=min(cnt,p[i.k][i.x]+p[j.k][j.x]+ans[i.k][j.k]);
				}
			}
		}
		cout<<cnt+w[x]+w[y]<<'\n';
	}
} 
