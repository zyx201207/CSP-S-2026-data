#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[2000005];
int dt[305][305];
int ans[305][305];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>x[i];
		}
		if(c<=6){
			for(int i = 1;i<=n;i++) for(int j = 1;j<=n;j++) if(abs(x[i]-x[j])<=d) dt[i][j]=dt[j][i]=1; else dt[i][j]=1e11;
			for(int k = 1;k<=n;k++){
				for(int i = 1;i<=n;i++){
					for(int j = 1;j<=n;j++){
						if(dt[i][k]+dt[k][j]<dt[i][j]){
							dt[i][j]=dt[i][k]+dt[k][j];
							ans[i][j]=0;
						} else if(dt[i][k]+dt[k][j]==dt[i][j]){
							ans[i][j]++;
						}
					} 
				}
			}
			int sum=0;
			for(int i = 1;i<=n;i++){
				for(int j = i+1;j<=n;j++){
					if(ans[i][j]==1){
						sum++;
					}
				}
			}
			cout<<sum<<endl;
		}else{
			cout<<n<<endl;
		}
	}
	
	return 0;
}
/*我不是区神 暴力写炸了 求CCF给我4~12pts*/
