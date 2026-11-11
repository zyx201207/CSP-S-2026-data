#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=500;
int c,T,n,d,a[N];
int dis[N][N],f[N][N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dis[i][j]=INT_MAX;
				f[i][j]=0;
			}
			dis[i][i]=0;
			f[1][1]=1;
		}
		for(int len=2;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				int j=i+len-1;
				if(a[j]-a[i]<=d){
					dis[i][j]=1;
					f[i][j]=1;
				}else{
					for(int k=i+1;k<j&&a[k]-a[i]<=d;k++){
						dis[i][j]=min(dis[i][j],dis[k][j]+1);
					}
				}
			}
		}
		for(int len=2;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				int j=i+len-1;
				for(int k=i+1;k<j&&a[k]-a[i]<=d;k++){
					if(dis[i][k]+dis[k][j]==dis[i][j]){
						f[i][j]=min((int)3,f[i][j]+f[i][k]*f[k][j]);
					}
				}
				if(f[i][j]==2){
					//cout<<"debug:"<<T<<' '<<i<<' '<<j<<endl;
					cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
