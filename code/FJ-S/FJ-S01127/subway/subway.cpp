#include <bits/stdc++.h>
#define zls rp++
#define ll long long
#define ull unsigned long long
using namespace std;
const ll inf=2e18;
int c,n,m,d,q,num[505];
ll w[500005],dis[505][505],limit;
struct node{int to;ll w;};
vector<node>l[500005];
void work(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(dis,0x3f,sizeof dis);
	limit=dis[0][0];
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		cin>>num[i];
		for(int j=1;j<=num[i];j++){
			int st;ll tm;
			cin>>st>>tm;
			l[st].push_back({i,tm});
		}
	}
	for(int i=1;i<=m;i++){
		int all=(int)l[i].size();
		for(int j=0;j<all;j++){
			int tj=l[i][j].to;
			ll vj=l[i][j].w;
			for(int k=j+1;k<all;k++){
				int tk=l[i][k].to;
				ll vk=l[i][k].w;
				dis[tj][tk]=dis[tk][tj]=min(dis[tj][tk],vj+vk);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++){
			if(dis[i][k]>=limit)continue;
			for(int j=i+1;j<=n;j++){
				if(dis[k][j]>=limit)continue;
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}	
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=w[x]+w[y],len=inf;
		for(node j:l[x])
			for(node k:l[y])
				len=min(len,j.w+k.w+dis[j.to][k.to]);
		cout<<ans+len<<'\n';
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	work();
	return 0;
}
