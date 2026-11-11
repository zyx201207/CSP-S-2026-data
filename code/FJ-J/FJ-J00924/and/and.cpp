#include<bits/stdc++.h>
using namespace std;
#define int long long
int T=1,n,m,ans=0;
int a[200010];

bool cmp(int a,int b){
	return a>b;
}
void dfs(int num,int t,int k){
	if(t==m){
		ans=max(ans,k);
		return ; 
	}
	if(num>n)return ;
	dfs(num+1,t,k);
	dfs(num+1,t+1,k&a[num]);
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(0,0,pow(2,32)-1);
		cout<<ans;
	}else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)ans=max(ans,i&j);
			}
		}
		cout<<ans;
	}else{
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans&= a[i];
		} 
		cout<<ans;
	}
} 

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
