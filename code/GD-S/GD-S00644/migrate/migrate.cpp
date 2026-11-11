#include<bits/stdc++.h>
using namespace std;
int const MAXN=2*1e6+5;
int n,d,a[MAXN],c,t,w[MAXN],cnt[MAXN],ans;
struct ss{
	int t,w;
};
queue<ss> q;
void bfs1(int x){
	q.push({x,0});
	while(!q.empty()){
		int t=q.front().t,s=q.front().w;
		q.pop();
		if(cnt[t]==0){
			cnt[t]++;
			w[t]=s;
		}
		else{
			if(s==w[t])
				cnt[t]++;
			else
				continue;
		}
		for(int i=t+1;i<=n;i++){
			if(a[i]-a[t]<=d){
				q.push({i,s+1});
			}
		}
	}
}
void bfs2(int x){
	q.push({x,0});
	while(!q.empty()){
		int t=q.front().t,s=q.front().w;
		q.pop();
		if(cnt[t]==0){
			cnt[t]++;
			w[t]=s;
		}
		else{
			if(s==w[t])
				cnt[t]++;
			else
				continue;
		}
		for(int i=t-1;i>=1;i--){
			if(a[t]-a[i]<=d){
				q.push({i,s+1});
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)	cin>>a[i];
		for(int i=1;i<=n;i++){
			memset(w,0,sizeof(w));
			memset(cnt,0,sizeof(cnt));
			bfs1(i);
			for(int j=1;j<=n;j++){
				if(cnt[j]==2 && i!=j){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

