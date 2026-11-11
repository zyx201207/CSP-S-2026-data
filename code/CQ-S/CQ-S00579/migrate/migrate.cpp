#include<bits/stdc++.h>
#define int long long
using namespace std;
void rf(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}int c,t,x[100005],n,d,mn,ans;
void dfs(int now,int end,int cnt){
	if(now==end){
		if(mn==cnt){
			ans++;
		}
		if(mn>cnt){
			mn=cnt;
			ans=1;
		}
	}
	for(int i=now+1;i<=end;i++){
		if(x[now]+d>=x[i]){
			dfs(i,end,cnt+1);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	rf();
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int cur=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mn=INT_MAX,ans=0;
				dfs(i,j,0);
				if(ans==2){
					cur++;
				}
			}
		}
		cout<<cur<<"\n";
	}
	return 0;
}
