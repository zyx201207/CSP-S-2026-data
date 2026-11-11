#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,ans;
ll a[2000007];
vector<ll> v[2000007];
queue<ll> q;
ll vis[2000007],dis[2000007],lj[2000007];
void bfs(int st){
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	memset(lj,0,sizeof(lj));
	q.push(st); 
	vis[st]=true; lj[st]=1;
	while(!q.empty()){
		ll cu=q.front();
		q.pop();
		for(ll to:v[cu]){
			if(!vis[to]){
				vis[to]=true;
				dis[to]=dis[cu]+1;
				lj[to]=lj[cu];
				q.push(to);
			}else if(dis[cu]+1==dis[to]){
				lj[to]+=lj[cu];
			}
		}
	}
	for(ll i=1;i<=n;i++)
		if(lj[i]==2)
			ans++;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		for(ll i=1;i<=n;i++)
			v[i].clear(),a[i]=0;
		cin>>n>>d; ans=0;
		for(ll i=1;i<=n;i++)
			cin>>a[i];
		if(c==11||c==12){	
			if(d>=2*(a[2]-a[1])){
				int x=d/(a[2]-a[1]);
				cout<<(n-2*x+2)*(n-2*x+1)/2<<"\n";
			}else{
				cout<<"0\n";
			}	
			continue;
		}
		for(ll i=2;i<=n;i++)
			for(ll j=1;j<i;j++)
				if(a[i]-a[j]<=d)
					v[j].push_back(i);
		for(ll i=1;i<=n;i++)
			bfs(i);
		cout<<ans<<"\n";
	}
	return 0;
}

