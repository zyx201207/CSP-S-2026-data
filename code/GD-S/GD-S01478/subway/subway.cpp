#include<bits/stdc++.h>
using namespace std;
bool mst;
struct edge{
	int to,tim;
};
int cnt=0;
int len[600005],head[600005];
int last[600005];
int jump[600005];
long long w[600005];
long long dp[505][505];
edge sub[600005];
bool med;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int id,tim;
			cin>>id>>tim;
			cnt++;
			len[id]++;
			if(len[id]==1)head[id]=cnt;
			jump[last[id]]=cnt,last[id]=cnt;
			sub[cnt]={i,tim};
		}
	}
	for(int i=1;i<=m;i++){
		int x=len[i],l=head[i],r;
		for(int a=0;a<x;a++,l=jump[l]){
			r=jump[l];
			for(int b=a+1;b<x;b++,r=jump[r]){
				int x=sub[l].to,y=sub[r].to;
				dp[x][y]=min(dp[x][y],0LL+sub[l].tim+sub[r].tim);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			dp[i][j]=dp[j][i];
		}
	}
	while(q--){
		int beg,ed;
		cin>>beg>>ed;
		long long ans=5e18;
		int l=head[beg];
		for(int i=1;i<=len[beg];i++,l=jump[l]){
			int r=head[ed];
			for(int j=1;j<=len[ed];j++,r=jump[r]){
				int x=sub[l].tim,y=sub[r].tim,a=sub[l].to,b=sub[r].to;
				ans=min(ans,x+y+dp[a][b]);
			}
		}
		cout<<ans+w[beg]+w[ed]<<"\n";
	}
	return 0;
}
