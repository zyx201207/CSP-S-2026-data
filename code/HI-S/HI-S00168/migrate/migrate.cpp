#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
ll ans,c,t,n,d,a[10000],cnt[10000],dd[10000];
vector<ll> v[10000];
queue<pi> q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i-1;a[i]-a[j]<=d && j>0;j--){
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			while(!q.empty()){
				q.pop();
			}
			for(int j=1;j<=n;j++){
				dd[j]=1e6,cnt[j]=0;
			}
			dd[i]=0,cnt[i]=0;
			q.push({i,0});
			while(!q.empty()){
				pi x=q.front();
				q.pop();
				if(dd[x.first]!=1e6){
					if(dd[x.first]==x.second){
						cnt[x.first]++;
					}
				}
				else{
					dd[x.first]=x.second;
					cnt[x.first]=1;
				}
				if(dd[x.first]<x.second){
					continue;
				}
				ll sz=v[x.first].size();
				for(int j=0;j<sz;j++){
					q.push({v[x.first][j],x.second+1});
				}
			}
			for(int j=1;j<=n;j++){
//				cout<<i<<' '<<j<<' '<<dd[j]<<' '<<cnt[j]<<'\n';
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans/2<<'\n';
	}
	return 0;
}

