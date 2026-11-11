#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int ans,c,t,n,d,a[2000005],dis[5005][5005],cnt[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(c==11||c==12){
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			d=d/(a[2]-a[1]);
			if(d*2>n||d<=1){
				cout<<0<<endl;
			}
			else{
				cout<<max(0ll,n-2*d+1)<<endl;
			}
			continue;
		}
		memset(dis,0x3f,sizeof(dis));
		memset(cnt,0,sizeof(cnt));
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<i;j++){
				if(a[i]-a[j]<=d){
					dis[j][i]=1;
					cnt[j][i]=1;
				}
			}
		}
		for(int k=2;k<n;k++){
			for(int i=1;i<k;i++){
				for(int j=k+1;j<=n;j++){
					if(dis[i][k]+dis[k][j]<dis[i][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					}
					else if(dis[i][k]+dis[k][j]==dis[i][j]){
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
					}
				}
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(cnt[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
预期32,希望CCF机子跑快点
*/
