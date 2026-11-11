#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[2000005],ans=LONG_MAX,ac;
int c,t,n,d;
void dfs(int step,int end,int cnt){
	if(step==end){
		if(cnt<ans){
			ans=cnt;
			ac=1;
		}
		else if(cnt==ans){
			ac++;
		}
		return ;
	}
	for(int i=step+1;i<=end;i++){
		if(abs(x[i]-x[step])<=d){
			dfs(i,end,cnt+1);
		}
		else{
			break;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int count=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=LONG_MAX,ac=0;
				dfs(i,j,0);
				if(ac==2){
					count++;
				}
			}
		}
		cout<<count<<'\n';
	}
	return 0;	
}
