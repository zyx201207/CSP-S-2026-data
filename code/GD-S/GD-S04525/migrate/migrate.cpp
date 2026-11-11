#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+5;
ll C,T,ans,n,d,a[N],cnt[N],dis[N],dx,p;
vector<ll>v[N];
queue<ll>q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		ans=0,dx=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			if(i==2)dx=a[i]-a[i-1];
			else if(i>2&&a[i]-a[i-1]!=dx)dx=-1;
		}
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		if(dx!=-1){
			if(d/dx<2)cout<<0<<"\n";
			else cout<<max(0ll,n-d/dx*2+1)<<"\n";
			continue;
		}
		for(ll i=1;i<=n;i++)v[i].clear();
		for(ll i=1;i<n;i++){
			for(ll j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					v[i].push_back(j);
					v[j].push_back(i);
				}
				else break;
			}
		}
		for(ll i=1;i<=n;i++){
			fill(cnt+1,cnt+1+n,0);
			fill(dis+1,dis+1+n,1e18);
			dis[i]=0;
			cnt[i]=1;
			q.push(i);
			while(!q.empty()){
				ll x=q.front();
				q.pop();
				for(auto y:v[x]){
					if(dis[y]>dis[x]+1){
						q.push(y);
						dis[y]=dis[x]+1;
						cnt[y]=cnt[x];
					}
					else if(dis[y]==dis[x]+1)cnt[y]+=cnt[x];
				}
			}
			for(ll j=1;j<=n;j++){
				if(j==i)continue;
				if(cnt[j]==2)ans++;
			}
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}

