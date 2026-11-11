//B就是n^2-一次到 
//n^3 打了个 
//怎么才 30 分 
//不做 T4 会不会寄掉 
#include<bits/stdc++.h>
#define int long long
using namespace std;
template<class T>
int binary(int l,int r,T cmp){
	while(l<r){
		int mid=l+(r-l)/2;
		cmp(mid)?l=mid+1:r=mid;
	}
	return l;
}
const int N=2e6+50;
int c,t,n,d,a[N];
namespace sol1{
	void solve(){
		int res=n*(n-1)/2;
		for(int i=1;i<=n;i++){
			int j=binary(i,n+1,[&](int x){
				return a[x]-a[i]<=d;
			})-1;
			res-=j-i;
		}
		printf("%lld\n",res);
	}
}
namespace sol2{
	int dis[N],f[N],ans;
	void bfs(int s){
		fill(dis+1,dis+1+n,1e18);
		fill(f+1,f+1+n,0);
		f[s]=1,dis[s]=0;
		queue<int>q;
		q.push(s);
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=1;i<=n;i++){
				if(x==i||abs(a[i]-a[x])>d)continue;
				if(dis[i]>dis[x]+1){
					q.push(i);
					dis[i]=dis[x]+1,f[i]=f[x];
				}else if(dis[i]==dis[x]+1){
					f[i]+=f[x];
				}
			} 
		}
//		for(int i=1;i<=n;i++){
//			cout<<dis[i]<<' ';
//		}
//		cout<<endl;
		for(int i=1;i<=n;i++){
			if(i==s||dis[i]==1e18)continue;
			if(f[i]==2)ans++;
		}
//		printf("%lld\n",ans);
	}
	void solve(){
		ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
		}
		printf("%lld\n",ans/2);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(c==13||c==14){
			sol1::solve();
		}
		if(c<=10){
			sol2::solve();
		}
	} 
	return 0;
}
