#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t;
int n,d,ans,sum;
int a[N];
void dfs(int u,int v,int k,int lc){
	if(k==v){
		if(ans==0){
			ans=lc;
			sum++;
		}else if(ans==lc){
			sum++;
		}
		return;
	}
	for(int i = k+1;i<=n;i++){
		if((a[i]-a[k])<=d){
			dfs(u,v,i,lc++);
		}else{
			return;
		}
	}
	
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int mx_sum=0;
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		for(int i = 1;i<n;i++){
			for(int j = i+1;j<=n;j++){
				ans=0,sum=0;
				dfs(i,j,i,0);
				mx_sum=max(mx_sum,sum);
			}
		}
		cout<<mx_sum/2<<'\n';
	}
	return 0;
}

