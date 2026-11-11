#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> g[21111];
int c,t,n,d,ans,s[21111],cnt[21111],dp1[21111],dp2[21111];
void spfa1(int x){
	queue <int> q;
	memset(dp1,0x3f,sizeof(dp1));
	q.push(x);
	dp1[x]=0;
	while (!q.empty()){
		int p=q.front();
		q.pop();
		for (int i=0;i<g[p].size();i++){
			if (dp1[g[p][i]]>dp1[p]+1){
				dp1[g[p][i]]=dp1[p]+1;
				q.push(g[p][i]);
			}
		}
	}
}
struct node{
	int px,k;
};
void spfa2(int x){
	queue <node> q;
	memset(dp2,0x3f,sizeof(dp2));
	q.push({x,0});
	dp2[x]=0;
	while (!q.empty()){
		int p=q.front().px,pk=q.front().k;
		q.pop();
		for (int i=0;i<g[p].size();i++){
			if (dp2[g[p][i]]>dp2[p]+1){
				dp2[g[p][i]]=dp2[p]+1;
				q.push({g[p][i],pk+1});
			}
			if (pk+1==dp1[g[p][i]]){
				cnt[g[p][i]]++;
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		memset(g,0,sizeof(g));
		ans=0;
		cin >> n >> d;
		for (int i=1;i<=n;i++){
			cin >> s[i];
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				if (s[j]-s[i]<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		for (int i=1;i<=n;i++){
			memset(cnt,0,sizeof(cnt));
			spfa1(i);
			spfa2(i);
			for (int j=i+1;j<=n;j++){
				if (cnt[j]==2){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
