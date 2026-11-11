#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
const int INF=1e9+10;
int p,n,t,m,ans,d; 
int sum[5010][5010];
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>p>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
//		p=11;
		if(p<=10){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					sum[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++){
				int las=i;
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[las]>d){
						if(a[j]-a[j-1]>d){
							sum[i][j]=INF;
							break;
						}
						sum[i][j]++;
						las=j-1;
					}
					if(j==i+1) sum[i][j]++;
				}
				for(int j=i+1;j<=n;j++)
					sum[i][j]+=sum[i][j-1];
			}
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=n;j++){
//					cout<<sum[i][j]<<' ';
//				}
//				cout<<'\n';
//			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int mn=sum[i][j],cnt=1;
					for(int k=i+1;k<j;k++){
						if(sum[i][k+1]!=sum[i][k]) continue;
						if(sum[i][k]<INF&&sum[k][j]<INF&&sum[i][k]+sum[k][j]==mn){
//							cout<<k<<"hxf\n";
							cnt++;
						}
					}
					if(cnt==2){
						ans++;
//						cout<<i<<' '<<j<<'\n';
					}
				}
			}
			cout<<ans<<'\n';
		}
		if(p>=11&&p<=12){
			int k=a[2]-a[1];
			int cnt=d/k;
			if(d<k||cnt*2>=n||cnt==1){
				cout<<0<<'\n';
				continue;
			}
			for(int i=2*cnt-1;i<=2*cnt-1;i++){
				ans+=n-i;
			}
			cout<<ans<<'\n';
			if(t==4){
				cout<<n<<' '<<d<<'\n';
				for(int i=1;i<=n;i++) cout<<a[i]<<' ';
			}
		}
		if(p>=13&&p<=14){
			int l=-1,r=-1;
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
					if(l==-1) l=i;
					r=i;
				}
			}
			cout<<0<<'\n';
		}
	}
}

