#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int a[N],vis[N],cnt[N];
int n,d;
void dfs(int u,int num){
	if (u>n)return;
	if (cnt[u]>num){
		vis[u]=1;
		cnt[u]=num;
	}
	else if (cnt[u]==num){
		vis[u]++;
	}
	for (int i=u+1;i<=n;i++){
		if (a[i]-a[u]<=d)dfs(i,num+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--){
		int sum=0;
		memset(vis,0,sizeof(vis));
		memset(cnt,0x3f,sizeof(cnt));
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];	
		}
		for (int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			memset(cnt,0x3f,sizeof(cnt));
			dfs(i,0);
			for (int j=i;j<=n;j++){
				if (vis[j]==2)sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
