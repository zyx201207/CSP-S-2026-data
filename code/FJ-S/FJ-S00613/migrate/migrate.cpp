#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=2e6+10;
int c,t;
int n;
ll x[MAXN];
ll d;
int dis[MAXN];
ll ans,cnt[MAXN];
struct node{
	int v;
	ll w;
};
queue<node> q;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++) cin>>x[i];
		
		for(int i=0;i<n;i++){
		    memset(dis,0x3f,sizeof(dis));
		    q.push({i,0});
		    while(!q.empty()){
		    	int v=q.front().v,w=q.front().w;
		    	q.pop();
		    	if(w<dis[v]){
		    		cnt[v]=1;
		    		dis[v]=w;
				}
				else if(w==dis[v]) cnt[v]++;
				
				for(int j=v+1;j<n;j++){
					if(abs(x[v]-x[j])<=d&&w+1<=dis[j]){
						q.push({j,w+1});
					}
					if(abs(x[v]-x[j])>d) break;
				}
			}
			for(int j=0;j<n;j++){
//				cout<<cnt[j]<<","<<dis[j]<<' ';
				if(cnt[j]==2) ans++;
			}
//			cout<<endl;
		}
		cout<<ans<<endl;
		ans=0;
	}
	
	return 0;
}
