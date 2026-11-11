#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
namespace CSPS{
	int n,k;
	int u[100005],v[100005];
	int dis[55][55];
	int count(int y){
		int cnt=0;
		while(y){
			cnt++;
			y=y&(y-1);
		}
		return cnt;
	}
	int lian(int y){
		int b=0;
		for(int i=2;i<=n;i++){
			if((y&(1<<u[i]-1))&&(y&(1<<v[i]-1)))b++;
		}
		return k-b;
	}
	int d(int u,int y){
		int p=INT_MAX;
		for(int i=0;i<n;i++){
			if(y&(1<<i)){
				p=min(p,dis[u][i+1]);
			}
		}
		return p;
	}
	int build(int f){
		int m=(n-1)/2;
		int u=f-1+f-1+2*(f-1)-1;
		return m-u;
	}
	void solve(int TC){
		if(TC==13||TC==14){
			cin>>n>>k;
			for(int i=2;i<=n;i++)cin>>u[i]>>v[i];
			int m=(n-1)/2;
			if(k==n)return cout<<0<<endl,void();
			if(k>=m)return cout<<1<<endl,void();
			int l=1,r=m,ans=m;
			while(l<=r){
				int mid=l+r>>1;
				if(build(mid)<=k)ans=mid,r=mid-1;
				else l=mid+1;
			}
			cout<<ans<<endl;
			return;
		}
		cin>>n>>k;
		memset(dis,32,sizeof(dis));
		for(int i=2;i<=n;i++)cin>>u[i]>>v[i],dis[u[i]][v[i]]=dis[v[i]][u[i]]=1;
		for(int i=1;i<=n;i++)dis[i][i]=0;
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		int ans=INT_MAX;
		for(int i=0;i<(1<<n);i++){
			if(count(i)!=k)continue;
			if(lian(i)>2)continue;
			int u=0;
			for(int j=1;j<=n;j++)u=max(u,d(j,i));
			ans=min(ans,u);
		}
		cout<<ans<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,Q=1;
	cin>>c>>Q;
	while(Q--)CSPS::solve(c);
//while(1);
	return 0;
}
/*

s MB
s MB
*/

