#include<bits/stdc++.h>
using namespace std;
long long w[514514];
long long dis[510][510];
vector<pair<long long,long long>> a[514514];
long long read(){
	long long ans=0;
	char c=getchar();
	while(c>='0'&&c<='9'){
		ans*=10;
		ans+=(c-'0');
		c=getchar();
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	c=read();
	m=read();
	n=read();
	d=read();
	q=read();
	for(long long i=1;i<=n;i++){
		w[i]=read();
	}
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=m;j++){
			dis[i][j]=LONG_LONG_MAX;
		}
		long long k;
		k=read();
		for(long long j=1;j<=k;j++){
			long long x,y;
			x=read();
			y=read();
			a[x].push_back({i,y});
		}
	}
	for(long long i=1;i<=n;i++){
		long long sz=a[i].size();
		for(long long j=0;j<sz;j++){
			for(long long k=0;k<sz;k++){
				dis[a[i][j].first][a[i][k].first]=min(dis[a[i][j].first][a[i][k].first],a[i][j].second+a[i][k].second);
			}
		}
	}
	for(long long i=1;i<=m;i++){
		dis[i][i]=0;
	}
	for(long long k=1;k<=m;k++){
		for(long long i=1;i<=m;i++){
			for(long long j=1;j<=m;j++){
				if(k==i||k==j||i==j){
					continue;
				}
				if(dis[i][k]==LONG_LONG_MAX||dis[k][j]==LONG_LONG_MAX){
					continue;
				}
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		long long x,y;
		x=read();
		y=read();
		long long ans=LONG_LONG_MAX;
		long long sz1=a[x].size();
		long long sz2=a[y].size();
		for(long long i=0;i<sz1;i++){
			for(long long j=0;j<sz2;j++){
				ans=min(ans,a[x][i].second+a[y][j].second+w[x]+w[y]+dis[a[x][i].first][a[y][j].first]);
			} 
		}
		cout<<ans<<endl;
	}
} 
//1800Byte
//1800Byte
//1800Byte
//1800Byte
//1800Byte
//1800Byte
//1800Byte
//1800Byte
// 1800B
