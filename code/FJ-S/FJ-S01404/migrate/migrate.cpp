#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
const int N=2e6+10;
const int INF=0x3f3f3f3f;
int c,t;
long long n,d;
long long a[N];
int e[310][310];
long long dis[310][310];
long long sum[310][310];
void check(int ca){
	long long b=d/ca;
	long long o=(n-1)%(b+1);
	cout << n-o << '\n';
	return;
}
void solve(){
	cin >> n >> d;
	bool f=true;
	long long ca;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i!=1) ca=a[i]-a[i-1]; 
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) f=false;
	}
	if(f){
		check(ca);
		return;
	}
		memset(e,INF,sizeof(e));
		memset(dis,INF,sizeof(dis));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) dis[i][j]=dis[j][i]=sum[j][i]=e[j][i]=sum[i][j]=e[i][j]=1;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=k;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][j]>dis[i][k]+dis[k][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
						sum[i][j]=sum[i][k]*sum[k][j];
					}else if(dis[i][j]==dis[i][k]+dis[k][j]){
						sum[i][j]+=sum[i][k]*sum[k][j];
					}
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){ 
				if(sum[i][j]==2){
					++cnt;
				} 
			}
		}
		cout << cnt << '\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--) solve();
}
