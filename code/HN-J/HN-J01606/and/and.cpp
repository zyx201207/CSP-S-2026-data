#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10,INF=1e9;
int n,m,a[N];
namespace subtack1{
	int ans=0;
	void dfs(int i,int sum,int c){
		if(i==n+1){
			if(c==m){
				ans=max(ans,sum);
			}
			return ;
		}
		if(!c){
			dfs(i+1,a[i],c+1);
		}else{
			dfs(i+1,sum&a[i],c+1);
		}
		
		dfs(i+1,sum,c);
	}
	void solve(){
		dfs(1,0,0);
		cout<<ans;
	}
}
namespace subtack2{
	int ans=0;
	void solve(){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
}
namespace subtack3{
	int ans=0;
	void solve(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
}
namespace subtack4{
	int ans=0;
	void solve(){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
}
namespace subtack5{
	int ans=0,minx=INF;
	void solve(){
		for(int i=1;i<=n;i++){
			minx=min(minx,a[i]);
		}
		if(a[1]==minx){
			ans=a[2];
			for(int i=3;i<=n;i++){
				ans&=a[i];
			}
		}else{
			ans=a[1];
			for(int i=2;i<=n;i++){
				if(a[i]==minx){
					minx=-1;
					continue;
				}
				ans&=a[i];
			}
		}
		cout<<ans;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}		
	if(n<=20) subtack1::solve();
	else if(m==2) subtack3::solve();
	else if(m==n) subtack4::solve();
	else if(m==n-1) subtack5::solve();
	else subtack2::solve();
	return 0;
}
