#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,ans=0;
typedef pair<ll,ll> p;
ll st[2000100],a[2000100];
ll dist[2000100],shuang[2000100];
void dijkstra(ll s){
	memset(st,false,sizeof st);
	memset(dist,0x3f3f3f3f3f3f3f3f,sizeof dist); 
	priority_queue<p,vector<p>,greater<p> > h;
	h.push({0,s});
	st[s]=true;
	while(!h.empty()){
		p k=h.top();
		ll u=k.second,cos=k.first;
		h.pop();
		for(ll i=s+1;i<=n;i++){
			if(st[i]) continue;
			else{
				if(abs(a[i]-a[u])<=d and dist[i]>=cos+1){
					st[i]=true;
					if(cos+1==dist[i]){
						shuang[i]++;
					}
					else{
						dist[i]=cos+1;
						shuang[i]=0;
					}
				}
			}
		}
	}
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++) cin>>a[i];
		for(ll i=1;i<=n;i++){
			dijkstra(i);
			for(ll j=i+1;j<=n;j++){
				if(shuang[j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
