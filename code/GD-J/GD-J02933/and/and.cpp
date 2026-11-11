#include<bits/stdc++.h>
using namespace std;
struct node{
	int w,id;
};
int n,m,cnt[32],vis[200005],a[200005],cou=0;
long long ans=0;
vector<node> g[32];
bool cmp(node a,node b){
	return a.w>b.w;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 	cin>>a[i];
	for(int i=1;i<=n;i++){
		int tmp=a[i],w=0;
		while(tmp>0){
			if(tmp%2==1) cnt[w]++,g[w].push_back({a[i],i});
			tmp/=2,w++;
		}
	}
	for(int i=30;i>=0;i--){
		if(cnt[i]<m){
			for(auto &t:g[i]){
				int d=t.id;
				a[d]-=(1<<i);
			}
			cnt[i]=0;
			continue;
		}
		cnt[i]=0;
		g[i].clear();
	}
	for(int i=1;i<=n;i++){
		int tmp=a[i],w=0;
		while(tmp>0){
			if(tmp%2==1) cnt[w]++,g[w].push_back({a[i],i});
			tmp/=2,w++;
		}
	}
	for(int i=30;i>=0;i--){
		if(cnt[i]>=m){
			sort(g[i].begin(),g[i].end(),cmp);
			int c=cou;
			for(int j=0;j<m;j++){
				if(vis[g[i][j].id]==0) cou++;
			}
			if(cou>m) cou=c;
			else{
				for(int j=0;j<m;j++){
				    if(vis[g[i][j].id]==0) vis[g[i][j].id]=1;
			    }
				ans+=(1<<i);
			}
		}
	}
	cout<<ans;
	return 0;
}
