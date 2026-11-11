#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2000005];
vector<int> v[5005];
int ans[2000005];
int dis[2000005],dis2[2000005];
bool f[2000005];
struct node{
	int x,y;
};
priority_queue<node> q;
bool operator < (node t1,node t2){
	return t1.y>t2.y;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n;
		ll m;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]<=a[i]+m){
					v[i].push_back(j);
				}
			}
		}
		ll sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[j]=1e9;
				dis2[j]=1e9;
			}
			memset(f,0,sizeof f);
			memset(ans,0,sizeof ans);
			dis[i]=0;
			dis2[i]=0;
			q.push({i,0});
			f[i]=1;
			while(!q.empty()){
				node t=q.top();
				q.pop();
				int d=t.x;
				for(int i=0;i<v[d].size();i++){
					int p=v[d][i];
					if(!f[p]&&dis[d]+1<dis[p]){
						dis[p]=dis[d]+1;
						f[p]=1;
						q.push({p,dis[p]});
					}
				}
			}
			q.push({i,0});
			while(!q.empty()){
				node t=q.top();
				q.pop();
				int d=t.x;
				for(int i=0;i<v[d].size();i++){
					int p=v[d][i];
					if(dis2[d]+1<=dis2[p]){
						dis2[p]=dis2[d]+1;
						if(dis2[p]==dis[p]) ans[p]++;
						q.push({p,dis2[p]});
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(ans[j]==2) sum++;
			}
		}
		cout<<sum<<endl;
		for(int i=1;i<=n;i++) v[i].clear();
	}
	return 0;
}
