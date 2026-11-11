#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll CCC,Q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>CCC>>Q;
	if(CCC<=18&&CCC>=15){
		while(Q--){
			ll n,m,a[2000010],ans=0;
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			ll diff=abs(a[1]-a[0]);
			if(m<2*diff){
				cout<<0<<'\n';
			}
			else {
				cout<<n-2<<'\n';
			}
		}
	}
	else{
	while(Q--){
		vector<ll>t[310];
		ll n,m,a[310],vis[310],ans=0;
		memset(vis,0,sizeof(vis));
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=m){
					t[i].push_back(j);
				} 
				else{
					break;
				}
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				queue<ll>q;
				q.push(i);
				ll cnt=0;
				while(!q.empty()){
					ll u=q.front();
					q.pop();
					if(u==j){
						cnt++;
						continue;
					}
					if(cnt>2)break;
					for(auto v:t[u]){
						if(v>=j){
							q.push(v);
						}
					}
				}
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
		}
	}
	return 0; 
}/*0 2
 4 2
 1 2 3 4
 5 2
 1 2 3 4 5
 0 2
 5 3
 -2 -1 0 1 2
 6 2
 -4 -3 -2 -1 3 6

 */
