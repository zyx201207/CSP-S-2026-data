#include<bits/stdc++.h>
#define ll long long
//priority_queue<int,vector<int>,greater<int>>
using namespace std;
struct node{
	ll a,t;
};
ll c,n,m,d,q;
unsigned long long ans,cnt;
bool sd[505][500005];
ll st[500005];
int b[505][500005];
vector<node>a[505];
bool vis[505];
void f(int e,int z,ll t){
	if(sd[z][e]){
		cnt=min((unsigned long long)t+b[z][e],cnt);
		return;
	}
	if(t>=cnt)return;
	for(auto i:a[z]){
		for(int j=1;j<=n;j++){
			if(vis[j]==0){
				if(sd[j][i.a]){
					vis[j]=1;
					f(e,j,t+i.t+b[j][i.a]);
					vis[j]=0;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>st[i];
	}
	for(int i=1;i<=n;i++){
		ll sum,x,y;
		cin>>sum;
		for(int j=1;j<=sum;j++){
			cin>>x>>y;
			a[i].push_back({x,y});
			b[i][x]=y;
			sd[i][x]=1;
		}
	}
	while(q--){
		int s,e;
		unsigned long long sum=LONG_LONG_MAX;
		cin>>s>>e;
		memset(vis,0,sizeof(vis));
		ans=st[s]+st[e];
		for(int i=1;i<=n;i++){
			cnt=LONG_LONG_MAX;
			if(sd[i][s]){
				if(sd[i][e]){
					sum=min(sum,(unsigned long long)b[i][s]+b[i][e]);
				}
				vis[s]=1;
				f(e,i,0); 
				sum=min(sum,b[i][s]+cnt);
				vis[s]=0;
			}
		}
		cout<<ans+sum<<endl;
	}
	return 0;
}

