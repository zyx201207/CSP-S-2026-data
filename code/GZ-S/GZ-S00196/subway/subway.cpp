#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v;
	long long wv;
};
long long maxa=1000000000086;
long long n,num,w[500005],d,p;
long long cost[600][600];//i到j线所需最小花费 
long long cs;
long long aa,tt;
node sta[500005][25];
long long ans=0;
long long rans;
long long sum[500005];
int x,y;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cs>>n>>num>>d>>p;
	for(long long i=1;i<=num;i++)cin>>w[i];
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++)
			cost[i][j]=cost[j][i]=maxa;
	}
	for(long long i=1,k;i<=n;i++){
		cin>>k;
		for(long long j=1;j<=k;j++){
			cin>>aa>>tt;
			sta[aa][++sum[aa]].v=i;
			sta[aa][sum[aa]].wv=tt;
		}
	}
	for(long long i=1;i<=num;i++){
		for(long long j=1;j<=sum[i];j++){
			for(long long k=1;k<=sum[i];k++){
				if(sta[i][j].v==sta[i][k].v){
					cost[sta[i][j].v][sta[i][k].v]=0;
					continue;
				}
				cost[sta[i][j].v][sta[i][k].v]=min(cost[sta[i][j].v][sta[i][k].v],sta[i][j].wv+sta[i][k].wv);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(cost[i][j]==0&&i!=j)cost[i][j]=maxa;
			for(int k=1;k<=n;k++){
				if(cost[i][k]==0||cost[k][j]==0)continue;
				cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
			}
		}
	}
	while(p--){
		cin>>x>>y;
		rans=w[x]+w[y];
		ans=maxa;
		for(int i=1;i<=sum[x];i++){
			for(int j=1;j<=sum[y];j++){
				ans=min(ans,rans+cost[sta[x][i].v][sta[y][j].v]+sta[x][i].wv+sta[y][j].wv);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
