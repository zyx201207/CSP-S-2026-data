#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int c,t,n,k,a[N],ans=2e9,d[N][N];
bool book[11],vis[N];
vector<int> v[N];
void dfs1(int u,int fa) {
	book[u]=1;
	for(int i=0; i<v[u].size(); i++) {
		if(v[u][i]==fa || !vis[v[u][i]] || book[v[u][i]]) continue;
		dfs1(v[u][i],u);
	}
}
void dfs(int cnt) {
	if(cnt==k) {
		int cnt=0,res=0;
		memset(book,0,sizeof book);
		for(int i=1; i<=k; i++)
			if(!book[i]){
				dfs1(i,0);
				cnt++;
				if(cnt>2) return;
			}
		for(int i=1; i<=n; i++) {
			int t=2e9;
			for(int j=1; j<=k; j++)
				t=min(t,d[i][a[j]]);
			cnt=max(cnt,t);
		}
//		if(ans>cnt) {
//			ans=cnt;
//			for(int i=1; i<=k; i++)
//				cout<<a[i]<<' ';
//			cout<<endl;
//		}
		ans=min(cnt,ans);	
		return;
	}
	for(int i=1; i<=n; i++) {
		if(vis[i]) continue;
		vis[i]=1;
		a[cnt+1]=i;
		dfs(cnt+1);
		vis[i]=0;
	}
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) {
		ans=2e9;
		memset(d,0x3f,sizeof d);
		scanf("%d%d",&n,&k);
		for(int i=1; i<=n; i++)
			v[i].clear();
		for(int i=1,u,b; i<n; i++) {
			scanf("%d%d",&u,&b);
			v[u].push_back(b);
			v[b].push_back(u);
			d[b][u]=d[u][b]=1;
		}
		for(int k=1; k<=n; k++)
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					if(d[i][j]>d[i][k]+d[k][j])
						d[i][j]=d[i][k]+d[k][j];
		dfs(0);
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
