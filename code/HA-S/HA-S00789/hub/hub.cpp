#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=110;
int C,T,n,k,d[110][110],c[110][110],mk[N],ans;
int head[N],tot;
struct edge {
	int u,v,nxt;
}e[N*2];
void add (int u,int v) {
	e[++tot].u=u;
	e[tot].v=v;
	e[tot].nxt=head[u];
	head[u]=tot;
}
vector<int>v;
bool check (int x) {
	for (int i=1;i<=n;i++) {
		int dis=1e9;
		for (int j=0;j<k;j++) {
			dis=min(dis,d[i][v[j]]);
		}
		if (dis>x) return 0;
	}
	//for (int i=1;i<=k;i++) cout << v[i-1] <<' ';
	//cout <<endl;
	return 1;
}
bool dfs (int x,int cnt,int t,int sum) {
	if (cnt==k) {
		if (check(x)) ans=1;
		return ans;
	}
	for (int i=t;i<=n;i++) {
		int flag=1;
		for (int j=0;j<cnt;j++) {
			if (c[i][v[j]]) {
				flag=0;
				break;
			}
		}
		if (sum+flag>=3) continue;
		v.push_back(i);
		dfs(x,cnt+1,i+1,sum+flag);
		v.pop_back();
		if (ans) return 1;
	}
	if (ans) return 1;
	return 0;
}
int main () {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> C >> T;
	while (T--) {
		cin >> n >> k;
		tot=0;
		memset(head,0,sizeof(head));
		for (int i=1;i<n;i++) {
			int a,b;
			cin >> a >> b;
			add(a,b);
			add(b,a);
		}
		if (n<=10) {
			memset(d,0x3f,sizeof(d));
			memset(c,0,sizeof(c));
			for (int i=1;i<=n;i++) d[i][i]=0;
			for (int i=1;i<=tot;i++) {
				d[e[i].u][e[i].v]=1;
				c[e[i].u][e[i].v]=1;
			}
			for (int k=1;k<=n;k++) {
				for (int i=1;i<=n;i++) {
					for (int j=1;j<=n;j++) {
						d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
						//cout << i <<' '<< j <<' '<<d[i][j] <<endl;
					}
				}
			}
			for (int i=0;i<=n;i++) {
				ans=0;
				if (dfs(i,0,1,0)) {
					cout << i <<endl;
					break;
				}
			}
		} 
	}
	return 0;
}
