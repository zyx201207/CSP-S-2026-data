#include<bits/stdc++.h>
using namespace std;
const int N=50005;
long long f[N][N];
long long a[N],cnt[N][N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) {
		memset(a,0,sizeof a);
		memset(cnt,0,sizeof cnt);
		long long n,d;
		cin>>n>>d;
		
		for(int i=1; i<=n; i++) {
			scanf("%lld",&a[i]);
		}
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(abs(a[j]-a[i])<=d)f[i][j]=1;
				else{
					f[i][j]=1e18;
				}
			}
		}
		for(int i=1; i<=n; i++)f[i][i]=0;
		for(int i=1; i<=n; i++) {
			for(int k=i+1; k<=n; k++) {
			//	if(a[k]-a[i]>d)break;
				for(int j=k+1; j<=n; j++) {
				//	if(a[j]-a[k]>d)break;
					if(f[i][k]+f[k][j]<f[i][j]) {
						f[i][j]=f[i][k]+f[k][j];
						cnt[i][j]=1;
					} else if(f[i][k]+f[k][j]==f[i][j]) {
						cnt[i][j]++;
					}
				//	if(t==2)cout<<cnt[i][j]<<" i="<<i<<" k="<<k<<" j="<<j<<endl;
				}
			}
		}
		long long sum=0;
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				//cout<<"i="<<i<<" J="<<j<<" "<<cnt[i][j]<<" "<<f[i][j]<<endl;
				if(cnt[i][j]==2)sum++;
			}
		}
		printf("%lld\n",sum);
	//	if(t==2)return 0;
	}
}
