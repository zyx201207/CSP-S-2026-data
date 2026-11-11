#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int,int>
const int N=2e5+100,mod=998244353;
int c,t;
int n,d;

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		vector<int> a(n+1),R(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			int l=i,r=n,mid,res=i;
			while(l<=r){
				mid=(l+r)>>1;
				if(a[mid]-a[i]<=d){
					l=mid+1,res=mid;
				}else{
					r=mid-1;
				}
			}
			R[i]=res;
		}
		int ans=0;
		for(int i=1;i<n;i++){
			queue<int> s;
			vector<pll> dis(n+1,{1e7,0});
			vector<bool> vis(n+1,0);
			for(int j=i+1;j<=R[i];j++){
				s.push(j),dis[j]={1,1};
			}
			while(!s.empty()){
				int to=s.front();
				s.pop();
				for(int j=to+1;j<=R[to];j++){
					s.push(R[j]);
					if(dis[to].first+1<dis[j].first){
						dis[j].first=dis[to].first+1,dis[j].second=dis[to].second;
					}else if(dis[to].first+1==dis[j].first){
						dis[j].second++;
					}
				}
			}
			for(int j=i+1;j<=n;j++){
				if(dis[j].first!=1e7&&dis[j].second==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

