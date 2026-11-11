#include<bits/stdc++.h>
using namespace std;
int c, t, n, d, x[20010], ans=INT_MAX, cnt, res, vis[20010];
void dfs(int xx, int en, int sum){
	if(xx==en){
		if(sum<ans){
			ans=sum;
			cnt=1;
		}
		else if(sum==ans){
			cnt++;
		}
		return ;
	}
	for(int i=xx+1; i<=en; i++){
		if(x[i]-x[xx]>d){
			break;
		}
		if(vis[i]==0){
			vis[i]=1;
			dfs(i, en, sum+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t--){
		res=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++){
			cin>>x[i];
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				for(int k=1; k<=10; k++){
					vis[k]=0;
				}
				cnt=0;
				ans=INT_MAX;
				dfs(i, j, 0);
				if(cnt==2){
					res++;
				}
			}
		}
		cout<<res<<'\n'; 
	}
	return 0;
} 
