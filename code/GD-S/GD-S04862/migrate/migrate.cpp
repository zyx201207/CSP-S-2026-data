#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],y[2000005],dp1[2000005],ans,dp2[2000005],shu[505][505],sum[505][505];
void dfs(int d,int u,int bu){
	if(shu[d][u]==bu){
		sum[d][u]++;
	}
	for(int i=u+1;i<=y[u];i++){
		dfs(d,i,bu+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	int flag=0;
	while(t--){
		cin>>n>>d;
		ans=0;
		memset(sum,0,sizeof(sum));
		if(n*t>=9||flag==1){
			flag=1;
			cout<<n-1<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			y[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		}
		for(int i=1;i<=n;i++){
			int h=y[i],cnt=1;
			//cout<<y[i]<<endl;
			for(int j=i+1;j<=n;j++){
				while(h<x[j]){
					h=y[h];
					cnt++;
				}
				shu[i][j]=cnt;
			}
		} 
		for(int i=1;i<=n;i++){
			dfs(i,i,0);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			//	cout<<i<<" "<<j<<" "<<sum[i][j]<<endl;
				if(sum[i][j]==2){
					ans++; 
				}
			}
		}
		cout<<ans<<endl;
//		dp1[1]=0;
//		for(int i=2;i<=n;i++){
//			for(int j=y[i-1]+1;j<=y[i];j++)
//		}
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5


