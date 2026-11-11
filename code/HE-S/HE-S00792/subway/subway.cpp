#include <bits/stdc++.h>
using namespace std;
long long C,n,m,d,q;
long long dis[510][510],cons[500100];
vector<long long>a[500100];
unordered_map<long long,long long>s[510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	memset(dis,0x3f3f3f3f,sizeof dis);
	for(long long i=1;i<=m;i++)cin>>cons[i];
	for(long long u=1;u<=n;u++){
//		cout<<u<<endl;
		long long k;
		cin>>k;
		long long t,tt;
		while(k--){
//			cin>>t>>tt;
			scanf("%lld%lld",&t,&tt);
			s[u][t]=tt;
			long long len=a[t].size();
			if(len!=0){
				for(long long now=0;now<len;now++){
					long long v=a[t][now];
					dis[u][v]=dis[v][u]=min(dis[u][v],
					s[v][t]+s[u][t]);
//					cout<<'?'<<v<<" ";
				}
			}
			a[t].push_back(u);
//			cout<<t<<" "<<a[t].size()<<";"<<endl;
		}
	}
	for(long long i=1;i<=n;i++)dis[i][i]=0;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			for(long long k=1;k<=n;k++){
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
//			cout<<dis[i][j]<<" ";
		}
//		puts("");
	}
	while(q--){
		long long u,v;
		scanf("%lld%lld",&u,&v);
		long long ans=0x3f3f3f3f3f3f;
		long long len1=a[u].size(),len2=a[v].size();
		for(long long i=0;i<len1;i++){
			long long l=a[u][i];
			for(long long j=0;j<len2;j++){
				long long r=a[v][j];
				ans=min(dis[l][r]+s[l][u]+s[r][v]
				,ans);
			}
		}
		printf("%lld\n",ans+cons[u]+cons[v]);
//		cout<<ans<<endl;
	}
	return 0;
}
