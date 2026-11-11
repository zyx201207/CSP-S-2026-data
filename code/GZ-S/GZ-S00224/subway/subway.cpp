//GZ-S00224 卓然 贵阳中天中学
#include<bits/stdc++.h>
using namespace std;
long long f[10005][10005];
long long a[500005];
long long w[500005];
long long t[500005];
long long n,q,d,mm;
long long c;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	cin>>mm>>n>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			f[i][j]=(long long)1e10;
		}
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	while(mm--){
		int k;cin>>k;
		for(int i=1;i<=k;i++)cin>>w[i]>>t[i];
		for(int i=1;i<=k;i++){
			for(int j=i+1;j<=k;j++){
				f[w[i]][w[j]]=min(f[w[i]][w[j]],t[i]+t[j]);
				f[w[j]][w[i]]=min(f[w[j]][w[i]],t[i]+t[j]);
			}
		}
		
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(f[i][j]==INT_MAX)cout<<-1<<" ";
//			else cout<<f[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(f[i][j]==INT_MAX)cout<<-1<<" ";
//			else cout<<f[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	
	while(q--){
		int x,y;cin>>x>>y;
		long long ans=f[x][y]+a[x]+a[y];
		cout<<ans<<endl;
	}
	return 0;
}

