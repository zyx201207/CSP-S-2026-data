#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int maxn=2e5+5;
int n,m,a[maxn],ok=1,all_and,max_num,vis[maxn],ans;

inline void solve(){
	int cur_ans;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			cur_ans=max(cur_ans,a[i]&a[j]);
			//cout<<i<<" "<<j<<'\n';
		}
	}
	cout<<cur_ans;
}

void dfs(int pos,int cnt,int cur_ans){
    //cout<<"pos "<<pos<<" a[pos] "<<a[pos]<<" cnt "<<cnt<<" cur_ans "<<cur_ans<<'\n';
	if(cnt==m) {ans=max(ans,cur_ans);return;}
	if(pos==n+1) return;
	dfs(pos+1,cnt,cur_ans);
	if(cnt==0) dfs(pos+1,cnt+1,a[pos]);
	else dfs(pos+1,cnt+1,cur_ans&a[pos]);
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];//cout<<i<<" ";
		if(a[i]!=i-1) ok=0;
		max_num=max(max_num,a[i]);
		all_and=all_and&a[i];
	}
	if(ok){
		cout<<n-m;
		return 0;
	}
	if(n==m){
		cout<<all_and;
		return 0;
	}
	if(m==1){
		cout<<max_num;
		return 0;
	}
	if(m==2) {
		solve();
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
