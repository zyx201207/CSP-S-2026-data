#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int c,t;
int n,d;
int x[N],cnt[N];
vector<int>eg[N];
queue<int>q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int pre=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			while((x[i]-x[pre])>d)pre++;
			for(int j=pre;j<i;j++){
				eg[j].push_back(i);
				eg[i].push_back(j);
			}
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			while(!q.empty())q.pop();
			memset(cnt,0,sizeof(cnt));
			q.push(j);
			cnt[j]=1;
			while(!q.empty()){
				int u=q.front();q.pop();
				for(int i=0;i<eg[u].size();i++){
					int v=eg[u][i];
					if(cnt[v]==1)ans++;
					else if(cnt[v]==2)ans--;
					cnt[v]++;
					if(cnt[v]>1)continue;
					q.push(v);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
