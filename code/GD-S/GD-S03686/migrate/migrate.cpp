#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005],cnt[5005],dp[5005];
int n,d;
void bfs(int x){
	memset(dp,0x3f,sizeof(dp));
	dp[x]=0;
	priority_queue<pair<int,int>> q;
	q.push({0,x});
	while(!q.empty()){
		auto t=q.top();
		q.pop();
		if(t.second==n)continue;
		int l,r,mid,ok;
		l=t.second+1,r=n,ok=t.second;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[mid]-a[t.second]<=d){
				ok=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		for(int i=t.second+1;i<=ok;i++){
			dp[i]=min(dp[i],t.first+1);
			q.push({t.first+1,i});
		}
	}
}
int bfs2(int x){
	memset(cnt,0,sizeof(cnt));
	int ans=0;
	priority_queue<pair<int,int>> q;
	q.push({0,x});
	while(!q.empty()){
		auto t=q.top();
		q.pop();
		if(dp[t.second]==t.first){
			if(cnt[t.second]==2) ans--;
			cnt[t.second]++;
			if(cnt[t.second]==2) ans++;
		} 
		if(t.second==n)continue;
		int l,r,mid,ok;
		l=t.second+1,r=n,ok=t.second;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[mid]-a[t.second]<=d){
				ok=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		for(int i=t.second+1;i<=ok;i++){
			q.push({t.first+1,i});	
		}
	}
	return ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=1,t=1;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			int ans=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			bfs(1);
			cout<<bfs2(1)*(n-d+1)<<"\n"; 
		}
	}
	else{
		while(t--){
			cin>>n>>d;
			int ans=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				bfs(i);
				ans+=bfs2(i);
			}
			cout<<ans<<"\n"; 
		}
	}
}
