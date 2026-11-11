#include<bits/stdc++.h>
using namespace std;
int t,n,sz[2000005];
long long m,a[2000005],cnt[2000005],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++){
			for(int j=i;j<=n;j++){
				cnt[j]=0;
				sz[j]=1e9;
			}
			cnt[i]=1;
			sz[i]=0;
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<j;k++)
					if(a[j]-a[k]<=m&&cnt[k]&&sz[k]+1<sz[j]){
						cnt[j]=cnt[k];
						sz[j]=sz[k]+1;
					}
					else if(a[j]-a[k]<=m&&cnt[k]&&sz[k]+1==sz[j])cnt[j]+=cnt[k];
				if(cnt[j]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
