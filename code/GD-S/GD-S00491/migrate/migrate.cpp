#include <bits/stdc++.h>
using namespace std;
long long n,a[2000000+10],t,d,c;
long long f[2010][2010];
long long sum[2010][2010],ans=0;
bool vis[2010]={0};
void dfs(long long x,long long p,long long s){
//	if(sum[x][y]!=0){
//		return sum[x][y];
//	}
//	long long u=0;
//	if(abs(a[x]-a[y])<=d)u++;
//	for(int i=1;i<=n;i++){
//		if(f[x][i]+f[i][y]==f[x][y] && i!=x && i!=y){
//			sum[x][y]+=dfs(x,i)*dfs(i,y);
//		}
//	}
//	return sum[x][y]+u;
	if(f[x][s]==p)sum[min(x,s)][max(x,s)]++;
	for(int i=1;i<=n;i++){
		if(i!=x && vis[i]==false && abs(a[i]-a[x])<=d){
			vis[i]=true;
			dfs(i,p+1,s);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		memset(f,0x3f,sizeof(f));
		memset(sum,0,sizeof(sum));
		ans=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			f[i][i]=0;
			sum[i][i]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					f[i][j]=min(f[i][j],1ll);
				}else break;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(f[i][k]!=f[1999][1999] && f[k][j]!=f[1999][1999])f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				for(int k=1;k<=n;k++){
//					if(k==i || k==j)c
//					if(a[i][k]+a[k][j]==a[i][j])sum[i][j]++;
//				}
//			}
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				sum[i][j]=dfs(i,j);
//				if(sum[i][j]==2)ans++;
//			}
//		}
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			vis[i]=true;
			dfs(i,0,i);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(sum[i][j]==2)ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
