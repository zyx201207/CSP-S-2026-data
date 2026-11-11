#include<bits/stdc++.h>
using namespace std;
const long long MAXN=500005;
const long long MAXX=600;
long long pos,vv[MAXX][MAXX],dp[MAXX][MAXX],c,n,hd[MAXX],cnt,m,d,q,w[MAXN],a,k,t,l,r,ans;
struct st{
	long long x,y;
};
struct stt{
	long long x,y;
	bool operator < (const stt &B)const{
		return y>B.y;
	}
}tmp;
priority_queue<stt>Q;
struct ll{
	long long to,nxt,zhi;
}v[MAXX*MAXX];
void add(long long x,long long y,long long z){
	cnt++;
	v[cnt].to=y;
	v[cnt].nxt=hd[x];
	v[cnt].zhi=z;
	hd[x]=cnt;
}
vector<st>shu[MAXN];
void djk(long long sa){
	dp[sa][sa]=0;
	Q.push({sa,0});
	while(!Q.empty()){
		tmp=Q.top();
		Q.pop();
		pos=tmp.x;
		for(long long i=hd[pos];i;i=v[i].nxt){
			long long p=v[i].to;
			if(dp[sa][p]>dp[sa][pos]+v[i].zhi){
				dp[sa][p]=dp[sa][pos]+v[i].zhi;
				Q.push({p,dp[sa][p]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++){
			scanf("%lld%lld",&a,&t);
			shu[a].push_back({i,t});
		}
	}
	memset(vv,0x3f,sizeof(vv));
	for(long long i=1;i<=m;i++){
		for(long long j=0;j<shu[i].size();j++){
			l=shu[i][j].x;
			for(long long p=j+1;p<shu[i].size();p++){
				r=shu[i][p].x;
				vv[l][r]=min(vv[l][r],shu[i][j].y+shu[i][p].y);
			}
		}
	}
	for(long long i=1;i<n;i++){
		for(long long j=i+1;j<=n;j++){
			if(!vv[i][j]&&!vv[j][i])continue;
			if(vv[i][j]){
				add(i,j,vv[i][j]);
				add(j,i,vv[i][j]); 
			}else{
				add(i,j,vv[j][i]);
				add(j,i,vv[j][i]);
			}
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(long long i=1;i<=n;i++)djk(i);
	for(long long i=1;i<=q;i++){
		scanf("%lld%lld",&l,&r);
		ans=-1;
		for(long long j=0;j<shu[l].size();j++){
			for(long long p=0;p<shu[r].size();p++){
				if(ans==-1)ans=dp[shu[l][j].x][shu[r][p].x]+shu[l][j].y+shu[r][p].y;
				else ans=min(ans,dp[shu[l][j].x][shu[r][p].x]+shu[l][j].y+shu[r][p].y);
			}
		}
		ans+=w[l];
		ans+=w[r];
		printf("%lld\n",ans);
	}
	return 0;
}
