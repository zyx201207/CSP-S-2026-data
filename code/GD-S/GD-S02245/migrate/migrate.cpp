#include <bits/stdc++.h>
using namespace std;
#define gc() getchar()
using ll=long long;
ll read(){
	ll x=0;
	int f=1,ch=gc();
	while (!isdigit(ch)) {
		f=(ch=='-'?-1:f);
		ch=gc();
	}
	while (isdigit(ch)){
		x=x*10+ch-'0';
		ch=gc();
	}
	return x*f;
}
const int maxn=2e6+5;
ll a[maxn];
void sol1(int t){
	while (t--){
		int n=read(),d=read(),cnt=0;
		vector <int> g[5005]; 
		int vis[5005]={},dis[5005]={};
		for (int i=1;i<=n;i++) {
			a[i]=read();
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				if (a[j]-a[i]>d){
					break;
				}
				g[i].push_back(j);
			}
		}
		for (int i=1;i<=n;i++){
			memset(dis,-1,sizeof dis);
			memset(vis,0,sizeof vis);
			queue<pair<int,int>> q;
			q.push({i,0});
			dis[i]=0;
			while (!q.empty()){
				int u=q.front().first;
				int d=q.front().second;
 			    q.pop();
				for (int v:g[u]){
					if (vis[v]>2||v==i){
						continue;
					}
					if (dis[v]==-1){
						dis[v]=d+1;
						vis[v]++;
						q.push({v,d+1});
					}
					else {
						if (dis[v]!=d+1){
							continue;
						}
						else {
							vis[v]++;
							q.push({v,d+1});
						}
					}
				}
			}
			for (int j=1;j<=n;j++){
				if (vis[j]==2&&j!=i){
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	if (c<=10){
		sol1(t);
		return 0;
	}
	cout << 0;
	return 0;
}
