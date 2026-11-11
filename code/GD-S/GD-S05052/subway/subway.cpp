#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],p[500005][2],dis[505][505],k,x,y,N,dt[505][505];
long long ans;
bool f[505];
struct tt{
	long long l,r;
}tmp;
vector<tt>t[500005];
long long dfs(int s,int e){
	if(s==e) return 0;
	if(dt[s][e]) return dt[s][e];
	long long tmp=N;
	for(int i=1;i<=n;i++){
		if(i!=s&&dis[s][i]!=N&&!f[i]){
			f[i]=1;
			tmp=min(tmp,dis[s][i]+dfs(i,e));
			f[i]=0;
		}
	}
	if(tmp!=N) dt[s][e]=tmp;
	return tmp;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	N=pow(2,62);
	//cin>>c>>n>>m>>d>>q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		//cin>>w[i];
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=N;
		}
	}
	for(int i=1;i<=n;i++){
		//cin>>k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			//cin>>x>>y;
			scanf("%lld%lld",&x,&y);
			for(int nw=0;nw<t[x].size();nw++){
				dis[i][t[x][nw].l]=dis[t[x][nw].l][i]=min(dis[i][t[x][nw].l],y+t[x][nw].r);
			}
			tmp.l=i;tmp.r=y;
			t[x].push_back(tmp);
		}
	}
	for(int i=0;i<q;i++){
		//cin>>x>>y;
		scanf("%lld%lld",&x,&y);
		ans=N;
		for(int j=0;j<t[x].size();j++){
			for(int nw=0;nw<t[y].size();nw++){
				for(int g=0;g<=n;g++){
					f[g]=0;
				} 
				f[t[x][j].l]=1;
				//cout<<t[x][j].l<<' '<<t[y][nw].l<<endl;
				ans=min(ans,w[x]+w[y]+t[x][j].r+t[y][nw].r+dfs(t[x][j].l,t[y][nw].l));
			}
		}
		cout<<ans<<endl;
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dis[i][j]<<' ';
		}
		cout<<endl;
	}
	*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
