#include<bits/stdc++.h> 
using namespace std;
long long c,t,n,d,a[2000007],ans,suam,res,vis[2000007];
void dfs(long long x,long long y,long long sum){
	if(x==y){
		if(ans<sum){
			ans=sum;
			suam=1;
		}
		else if(ans==sum){
			suam++;
		}
	}
	for(long long i=1;i<=n;i++){
		if(abs( a[x]-a[i])<=d){
			vis[i]=1;
		dfs(i,y,sum+abs(a[x]-a[i]));
		vis[i]=0;
		}
	}
}
int main() {
	freopen("migrat.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	if(c==13||c==14){
	}else{
		while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				for(long long k=1;k<=n;k++)vis[k]=0;
		ans=0,suam=0;
				dfs(i,j,0);
				if(suam==2){
					res++;
				}
			}
		}
	}
	}
	cout<<res;
	}
	return 0;
}
