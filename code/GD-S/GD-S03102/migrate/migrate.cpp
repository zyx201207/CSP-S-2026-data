#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2100000];
int U,V;
vector<int>path_sum;
void dfs(int u,int sum,int cnt){
	if(cnt>n){
		return;
	}
	if(u==V){
		path_sum.push_back(sum);
		return;
	}
	for(int i=u+1;i<=n;i++){
		if(i!=u){
			if(abs(a[i]-a[u])<=d){
				dfs(i,sum+abs(a[i]-a[u]),cnt+1);
			}else{
				return;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(U=1;U<=n;U++){
			for(V=U+1;V<=n;V++){
				path_sum.clear();
				dfs(U,0,0);
				ans+=path_sum.size()==3;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
