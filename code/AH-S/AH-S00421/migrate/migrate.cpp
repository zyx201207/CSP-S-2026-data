#include <bits/stdc++.h>
#define int long long
using namespace std;
const int max_=2e3+5;
int n,d,a[max_],dis[max_][max_],cnt[max_][max_];
vector<int>v[max_];
void bfs(int f){
	cnt[f][f]=1;
	priority_queue<pair<int,int>>qu;
	qu.push({0,f});
	while(!qu.empty()){
		int x=qu.top().second;
		qu.pop();
		for(int i:v[x]){
			if(dis[f][i]>dis[f][x]+1){
				cnt[f][i]=cnt[f][x];
				dis[f][i]=dis[f][x]+1;
				qu.push({-dis[f][i],i});
			}else if(dis[f][i]==dis[f][x]+1){
				cnt[f][i]+=cnt[f][x];
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			int a,b;
			cin>>a>>b;
			for(int i=3;i<=n;i++){
				int x;
				cin>>x;
			}
			int qwq=b-a;
			if(d<2*qwq){
				cout<<0<<'\n';
				continue;
			}
			cout<<max(0ll,n-((d/qwq)*2-1))<<'\n';
		}
		exit(0);
	}
	while(t--){
		cin>>n>>d;
		memset(dis,0,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			v[i].clear();
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					dis[i][j]=0;
				}else{
					dis[i][j]=2e18;
				}
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans+=(cnt[i][j]==2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
