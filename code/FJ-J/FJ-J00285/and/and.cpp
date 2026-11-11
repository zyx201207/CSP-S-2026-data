#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int cnt;
int a[200005];
void dfs(int x,int p,int sum){
	if(x>m){
		cnt=max(cnt,sum);
		return ;
	}if(p>n) {
		return ;
	}
	dfs(x+1,p+1,sum&a[p]);
	dfs(x,p+1,sum);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=a[i]&ans;
		}cout<<ans;
		return 0;
	}if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}cout<<ans;
		return 0;
	}
	if(n<=20){
		for(int i=1;i<=n-m+1;i++){
			dfs(1,i,a[i]);
		}
		cout<<cnt;
		return 0;
	}
	cout<<a[n-m+1];
	return 0;
}
