#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 200005

ll n,m,a[MAXN],vis[MAXN],maxx;

vector<ll>ans;

void dfs(ll d){
	if(d==m+1){
		ll res=(1<<31)-1;
		for(int i=0;i<(int)ans.size();i++) res=(res&ans[i]);
		maxx=max(maxx,res);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			ans.push_back(a[i]);
			dfs(d+1);
			ans.pop_back();
			vis[i]=0;
		}
	}
	return;
}

priority_queue<ll>q;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	ll res=(1<<31)-1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		res=(res&a[i]);
	}
	if(n==m){
		cout<<res;
		return 0;
	}
	if(n<=20){
		dfs(1);
		cout<<maxx;
		return 0;
	}else{
		if(m==1){
			for(ll i=1;i<=n;i++) q.push(a[i]);
			cout<<q.top();
			return 0;
		}else if(m==n){
			cout<<res;
			return 0;
		}else if(m==2){
			dfs(1);
			cout<<maxx;
			return 0;
		}else if(m==n-1){
			for(int i=1;i<=n;i++){
				res=(1<<31)-1;
				for(int j=1;j<=n;j++){
					if(i==j) continue;
					res=(res&a[j]);
				}
				maxx=max(maxx,res);
				cout<<maxx;
				return 0;
			}
		}else{
			dfs(1);
			cout<<maxx;
			return 0;
		}
	}
	cout<<maxx;
	return 0;
}
