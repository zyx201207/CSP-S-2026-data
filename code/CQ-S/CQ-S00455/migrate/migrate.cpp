#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000005],cnt[2000005],sum[2000005];
bool check(){
	for(int i=2;i<n;i++){
		if((a[i-1]+a[i+1])!=(2*a[i])){
			return false;
		}
	}
	return true;
}
vector<int> g[5005];
struct node{
	int to;
	int val;
};
queue<node> q;
void bfs(int st){
	for(int i=1;i<=n;i++){
		sum[i]=1e18;
		cnt[i]=0;
	}
	sum[st]=0;
	cnt[st]=1;
	q.push({st,0});
	while(!q.empty()){
		node kkk=q.front();
		q.pop();
		if(kkk.val!=sum[kkk.to]){
			continue;
		}
		for(auto i:g[kkk.to]){
			if(sum[i]>sum[kkk.to]+1){
				sum[i]=sum[kkk.to]+1;
				cnt[i]=1;
				q.push({i,sum[kkk.to]+1});
			}
			else if(sum[i]==sum[kkk.to]+1){
				cnt[i]++;
				q.push({i,sum[kkk.to]+1});
			} 
		}
	}
}
void kjq(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(check()){
		int k=d/(a[2]-a[1]);
		if(k==0||k==1){
			cout<<0<<'\n';
			return;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(i+2*k-1<=n){
				ans++;
			}
		}
		cout<<ans<<'\n';
		return;
	}
	if(n<=300){
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					g[i].push_back(j);
				}
				else{
					break;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
		return;
	}
	cout<<0<<'\n';
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		kjq();
	}
	return 0;
}
//rp++
//32pts
