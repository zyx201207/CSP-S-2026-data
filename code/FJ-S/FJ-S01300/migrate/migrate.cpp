#include<bits/stdc++.h>
using namespace std;
int c,t;
long long ac[1005],dp[5001][5001],a[5001][5001];
long long bc[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(0<=c&&c<=10){
		while(t--){
			int ans=0;
			long long n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>ac[i];
//			for(int i=1;i<=n;i++){
//				dp[i][i+1]=1;
//			}
			for(int i=n;i>=1;i--){
				for(int j=i+1;j<=n;j++){
					int k=i;
					if(ac[j]-ac[i]<=d)a[i][j]=1,dp[i][j]=1,k=j;
					else{
						while(ac[k]-ac[i]<=d)k++;
						a[i][j]=a[k-1][j]+1;
					}
					int s=1;
					while(k-s>i&&a[i][j]==a[k-s][j]+1){
						dp[i][j]+=dp[k-s][j];
						s++;
						if(dp[i][j]>2)break;
					}
				}
			}
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=n;j++)cout<<dp[i][j]<<' ';
//				cout<<'\n';
//			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(dp[i][j]==2)ans++;
				}
			}
			printf("%d\n",ans);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					a[i][j]=0;
					dp[i][j]=0;
				}
			}
		}
	}else if(c==11||c==12){
		while(t--){
			long long n,d;
			cin>>n>>d;
			long long dca,dcb;
			for(int i=1;i<=n-1;i++)scanf("%lld",&dca);
			scanf("%lld",&dcb);
			long long gc=dcb-dca;
			long long bs=d/gc;
			if(bs==1||bs==0||n-2*bs+1<0)cout<<0<<endl;
			else cout<<n-2*bs+1<<endl;
		}
	} 
	return 0;
}

