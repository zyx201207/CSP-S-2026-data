#include<bits/stdc++.h>
#define int long long
using namespace std;

int arr[200010],n,m,res;

void dfs(int x,int sum,int cnt){
	if(x>n||sum==m){
		if(sum==m){
			res=max(res,cnt);
		}
		return ;
	}
	dfs(x+1,sum+1,cnt&arr[x]);
	dfs(x+1,sum,cnt);
}

void solve(){
	dfs(1,0,2147483647);
	cout<<res;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(n<=20){
		solve();
	}else if(n<=2000){
		if(m==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				ans=max(ans,arr[i]);
			}
			cout<<ans;
		}else if(m==n){
			int ans=arr[1];
			for(int i=2;i<=n;i++){
				ans=ans&arr[i];
			}
			cout<<ans;
		}else if(m==2){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=max(ans,arr[i]&arr[j]);
				}
			}
			cout<<ans;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}

