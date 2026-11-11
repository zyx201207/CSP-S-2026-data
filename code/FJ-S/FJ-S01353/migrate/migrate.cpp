#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+10;
int c,t,n;
ll ans,d,x[N],e[N][N],cnt[N][N];
void start(){
	ans=0;
	for(int i=1;i<=n;i++){
		e[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			e[i][j]=e[j][i]=1e17;
		}
	}
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j || j==k || i==k){
					continue;
				}
				if(e[i][j]==e[i][k]+e[k][j] && e[i][j]<1e17 && e[i][k]<1e17 && e[k][j]<1e17){
					cnt[i][j]+=cnt[i][k]*cnt[k][j];	
				}else if(e[i][j]>e[i][k]+e[k][j]){
					cnt[i][j]=1;
					e[i][j]=e[i][k]+e[k][j];
				}
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		start();
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int lst=1;
		for(int i=1;i<=n;i++){
			while(x[i]-x[lst]>d){
				lst++;
			}
			for(int j=lst;j<i;j++){
				e[i][j]=e[j][i]=1;
				cnt[i][j]=cnt[j][i]=1;
			}
		}
		floyd();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j && cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans/2<<'\n';
	}
	return 0;
}
