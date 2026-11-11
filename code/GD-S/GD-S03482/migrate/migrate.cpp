#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
typedef long long ll;
int n,d,c,t,q,a[maxn],cnt;
vector<int> g[maxn];
bool bfs(int x,int y) {
	queue<pair<string,int>> qq;
	string s=to_string(x);
	qq.push({s,x});
	int num=0;
	string ans="#";
	while(!qq.empty()) {
		int v=qq.front().second;
		string s1=qq.front().first;
		qq.pop();
		int l=g[v].size();
		for(int i=0;i<l;i++) {
			int u=g[v][i];
			string s2=s1+to_string(u);
			if(u==y&&ans=="#") num=1,ans=s2;
			if(u==y&&ans!="#"&&ans!=s2) num++;
		}
	}
	if(num==2) return true;
	else return false;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t) {
		t--,cnt=0;
		memset(d,0,sizeof(d));
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) {
			int j=i;
			while(a[j]-a[i]<=d) g[i].push_back(j);
		}
		for(int i=1;i<n;i++) {
			for(int j=i+1;j<=n;j++) {
				if(bfs(a[i],a[j])) cnt++;
			}
		}
		printf("%d",cnt);
	}
	return 0;
}
