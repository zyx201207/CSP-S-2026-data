#include <bits/stdc++.h>
using namespace std;
const long long N=5e2+5,M=5e5+5,inf=1e18;
long long c,n,m,d,q,a[M],k[N],u,t,v,f[N][N];
vector<pair<long long,long long>> g[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>a[i];
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>u>>t;
			g[u].push_back({i,t});
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			f[i][j]=inf;
		}
	}
	for(long long i=1;i<=m;i++){
		long long s=g[i].size();
		for(long long x=0;x<s;x++){
			for(long long y=0;y<s;y++){
				f[g[i][x].first][g[i][y].first]=min(f[g[i][x].first][g[i][y].first],g[i][x].second+g[i][y].second);
			}
		}
	}
	for(long long i=1;i<=n;i++) f[i][i]=0;
	for(long long k=1;k<=n;k++){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>u>>v;
		long long ans=inf;
		for(auto x:g[u]){
			for(auto y:g[v]){
				ans=min(ans,x.second+y.second+f[x.first][y.first]);
			}
		}
		cout<<ans+a[u]+a[v]<<"\n";
	}
	return 0;
}




//14:50 ACT1
//T234都好难，T2一看就是二分图，可我不会。
//尝试手推二分图性质。
//我快要放弃了，搞了一年各种算法，结果T2是个就提了一嘴的二分图？？？
//算算打爆力的分：100+44+40+15=199？神秘的分数,1=无望啊。 
//呜呜呜，肚子的你没有心。看在我给C*F捐了四千多的份上让我场切一次T2不行吗。 
//我寄愁心与明月，门前冷落鞍马稀。 
//16:29 我好像有思路了，Floyd助我。 
//17:10 ACT2
//哈哈哈哈哈，我太强了。 
//求1= 
