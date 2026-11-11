#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m;
//vector<int>tmp;
int a[N];int ans;
void dfs(int idx,int cnt,int sum,vector<int>tmp){
	if(cnt==m){
		ans=max(ans,sum);
		for(auto it:tmp)cout<<it<<' ';
		cout<<'\n';
		return;
	}
	if(idx==n||sum<=ans)return;
	tmp.push_back(a[idx]);
	dfs(idx+1,cnt+1,sum&a[idx],tmp);
	tmp.pop_back();
	dfs(idx+1,cnt,sum,tmp);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	vector<int>tmppp;
//	dfs(1,0,pow(2,35)-1,tmppp);
//	cout<<ans;
sort(a+1,a+n+1);
cout<<a[n-m+1];
} 
