#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct node {
	long long v,w;
	node(int i=0,int j=0,int k=0):v(i),w(j){}
	bool operator<(node a) const {return w>a.w;}
};
long long c,t,n,d,a[N],num[N],dis[N],ans;
vector<int> g[N];
priority_queue<node> que;
void dij(int st) {	
	for(int i=1;i<=n;i++) dis[i]=2e18,num[i]=0; 
	dis[st]=0;
	que.push(node(st,0));
	while(!que.empty()) {
		int x=que.top().v,t=que.top().w;
		que.pop();
		for(int i=0;i<g[x].size();i++) {
			if(t+1<dis[g[x][i]]) {
				dis[g[x][i]]=t+1;
				num[g[x][i]]=1;
				que.push(node(g[x][i],dis[g[x][i]]));
			}else if(t+1==dis[g[x][i]])	{
				num[g[x][i]]++;
			}
		}
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int k=1;k<=t;k++) {
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=0;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++) {
			int l=i,r=n,id=i;
			while(l<=r) {
				int mid=(l+r)/2;
				if(a[mid]-a[i]<=d) id=mid,l=mid+1;
				else r=mid-1;
			}
			for(int j=i+1;j<=id;j++)
				g[i].push_back(j);
		}
		for(int i=1;i<=n;i++) {
			dij(i);
			for(int j=1;j<=n;j++) {
				if(num[j]==2) ans++;
			}
		}
		cout<<ans<<"\n"; 
	}
	return 0;
}
