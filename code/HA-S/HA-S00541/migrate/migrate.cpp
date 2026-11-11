#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,c;
}b[2000010];
vector<int>g[2000010];
long long c,T,n,d,a[2000010],ans;
int ru[2000010],ru1[2000010];
queue<int>q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			g[i].clear();
			ru[i]=0;
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d) break;
				g[i].push_back(j);
				ru[j]++;
			}
		}
		for(int i=1;i<=n;i++){
			for(auto v:g[i-1]) ru[v]--;
			for(int j=i;j<=n;j++){
				b[j].c=b[j].x=0x3f3f3f3f;
				ru1[j]=ru[j];
			}
			q.push(i);
			b[i].c=b[i].x=0;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(auto v:g[u]){
					if(b[v].x<b[u].x+1) ;
					else if(b[v].x==b[u].x+1) b[v].c++;
					else {
						b[v].x=b[u].x+1;
						b[v].c=1;
					}
					ru1[v]--;
					if(ru1[v]==0) q.push(v);
				}
			}
			for(int j=i;j<=n;j++){
				//cout<<b[j].x<<" "<<b[j].c<<endl;
				if(b[j].c==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

