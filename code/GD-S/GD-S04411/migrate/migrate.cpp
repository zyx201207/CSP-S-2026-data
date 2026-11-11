#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,ans2,ans,sum2;
int a[1005];
void dfs2(int now,int e,int sum){
//	if(e==6)cout<<now<<' ';
	
	if(now>=e){
		ans2=sum;
		return ;
	}
//	if(now==1&&e==4)cout<<now<<' '; 
	for(int i=now+1;i<=n;i++){
		if(a[now]+d>=a[i]&&a[now]+d<a[i+1]){
			dfs2(i,e,sum+1);
		}
	}
}
void dfs(int now,int e,int sum){
	if(now>=e||sum>=ans2){
		if(now==e&&sum==ans2)ans++;
		return ;
	}
	for(int i=now+1;i<=e;i++){
		if(a[now]+d>=a[i]){
			dfs(i,e,sum+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans2=0;
		ans=0;
		sum2=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		a[n+1]=int(1e9);
		for(int i=1;i<=n;i++){
			
			for(int j=i+1;j<=n;j++){
				ans=0;
				ans2=0;
				dfs2(i,j,0);
				//if(i==1&&j==4)cout<<ans2<<" ";
				dfs(i,j,0);
				if(ans==2){
				//	cout<<i<<' '<<j<<endl;
					sum2++;
				}
			}
		}
		cout<<sum2<<endl;
	}
	return 0;
} 
