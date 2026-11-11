#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000005],p=0,ans=0,sum=0;
void dfs(int st,int en,int sum){
	if(sum==0&&st==en){
		p++;
		return;
	}
	else if(sum==0)return;
	for(int i=st+1;i<=en;++i){
		if(x[i]-x[st]<=d)dfs(i,en,sum-1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
		}
		for(int i=1;i<=n;++i){
			for(int j=i+3;j<=n;++j){
				sum=0,p=0;
				for(int l=i,r=l+1;l<=j&&r<=j;++r){
					if(x[r]-x[l]>d){
						sum++;
						l=r-1;
					}
					if(r==j){
						sum++;
						break;
					}
				} 
				
				dfs(i,j,sum);
				if(p==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
