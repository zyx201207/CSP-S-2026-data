#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>
using namespace std;
const int N=2e6+10;
using ll=long long;
ll x[N];
vector<pair<int,int> > s[N];
int l[N],r[N];
int vis[N],dis[N];
void solve(){
	int n;
	ll d;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;++i)scanf("%lld",&x[i]);
	for(int i=1;i<=n;++i){
		s[i].clear();
		l[i]=lower_bound(x+1,x+1+n,x[i]-d)-x;
		r[i]=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
//		cout<<l[i]<<" "<<r[i]<<"\n";
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)vis[j]=0,dis[j]=1e9;
		s[i].push_back({0,i});
		sort(s[i].begin(),s[i].end());
		vector<pair<int,int> > tmp;
		for(auto j:s[i]){
//			printf("(%d %d) ",j.second,j.first);
			if(vis[j.second]>2)continue;
			if(dis[j.second]<j.first)continue;
			dis[j.second]=j.first;
			++vis[j.second];
			tmp.push_back(j);
		}
//		for(auto j:tmp)
//			printf("(%d %d) ",j.second,j.first);
		for(int i=1;i<=n;++i)if(vis[i]==2)++ans;
		for(int j=i+1;j<=r[i];++j){
			for(auto k:tmp){
				s[j].emplace_back(k.first+1,k.second);
			}
		}
//		cout<<"\n";
	}
	
//	ll ans=0;
	printf("%lld\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	for(cin>>c>>t;t;--t)solve();
	return 0;
}
