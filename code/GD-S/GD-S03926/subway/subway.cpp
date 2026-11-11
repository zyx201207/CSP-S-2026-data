#include<bits/stdc++.h>
using namespace std;
#define int long long
int _,n,m,d,T;
int w[500005];
int x[1005][1005];
int s;
int wss[503][1005];
int ss[503];
bool vis[1005];
int dfs(int a,int b,int now,int bu){
	if(now==b)return bu;
	if(vis[now]=1)return 0x3f3f3f3f;
	vis[now]=1;
	int cnt=0x3f3f3f3f;
	for(int i=1;i<=m;i++){
		if(x[a][i]!=0)
		cnt=min(cnt,dfs(a,b,i,bu+2*s));
	}
	vis[now]=0;
	return cnt;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>_>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ss[i];
		for(int j=1;j<=ss[i];j++){
			int a,b;
			cin>>a>>b;
			s=b;
			wss[i][j]=a;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=ss[i];j++){
			for(int k=1;k<=ss[i];k++){
				if(j!=k){
					x[wss[i][j]][wss[i][k]]=1;
					x[wss[i][k]][wss[i][j]]=1;
				}
			}
		}
	}
	while(T--){
		int a,b;
		cin>>a>>b;
		cout<<dfs(a,b,a,0)+w[a]+w[b]<<'\n';
	}
} 
