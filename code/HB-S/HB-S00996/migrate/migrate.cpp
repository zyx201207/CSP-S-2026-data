#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],ans,l;
void dfs(int now,int cnt,int sum){
	if(cnt>ans) return ;
	if(now==n+1 || sum==0){
		ans=min(ans,cnt);
		if(ans==cnt) l++;
		return ;
	}
	for(int j=n;j>=1;--j){
		sum=j;
		for(int i=1;i<=n;++i){
			if(sum>=d){
				dfs(now+d,cnt+1,sum-d);
			}	
			else{
				dfs(now+sum,cnt+1,sum-sum);
			}
		}
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;++i){
		cin>>n>>d;
		for(int j=1;j<=n;++j){
			cin>>x[j];
		}
		dfs(1,0,n);
		cout<<l<<'\n';
	}
	return 0;
}
