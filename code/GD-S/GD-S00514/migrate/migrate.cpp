#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int c,T,n,d;
int a[N];
int ans;
int dis[N];
struct edge{
	int now,s;
};
bool bfs(int st,int ed){
	queue<edge>q;
	q.push({st,0});
	for(int i=1;i<=n;i++)dis[i]=1e18;
	int ji=0,minn=INT_MAX;
	while(!q.empty()){
		edge u=q.front();
		q.pop();
		dis[u.now]=u.s;	
		if(u.now==ed){
			ji++;
			if(ji==1){
				minn=u.s;
			}else if(ji==2&&minn!=u.s){
				return false;
			}else if(ji==3&&minn!=u.s){
				return true;
			}else if(ji==3&&minn==u.s){
				return false;
			}
		}
		for(int i=u.now+1;i<=ed;i++){
			if(a[i]-a[u.now]>d)break;
			if(u.s+1>dis[i])continue;
			q.push({i,u.s+1});
		}
	}
	if(ji==2)return true;
	else return false;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);
		ans=0;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(11<=c&&c<=12){
			ans=n-d/(a[2]-a[1])*2+1;
			if(ans<0||d<=a[2]-a[1])cout<<0<<"\n";
			else cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(bfs(i,j))ans++;
			}
		}
		printf("%lld\n",ans);
	}
} 
