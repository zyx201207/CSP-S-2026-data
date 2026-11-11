#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[2000006],sum[2000006],minn[2000006],cnt[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	minn[0]=0x3f3f3f3f3f3f3f3f;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)sum[j]=minn[j]=0;
			for(int j=1;j<=n;j++)cnt[j]=0;
			sum[i]=1;
			minn[i]=0;
			cnt[0]=1;
			for(int j=i+1;j<=n;j++){
				int minid=0,k;
				for(k=j-1;k>=i&&a[j]-a[k]<=d;k--){
					if(minn[k]+1<minn[minid]+1){
						minid=k;
					}
				}
				if(k==0)break;
				if(k>=i)cnt[minn[k]]-=sum[k];
				minn[j]=minn[minid]+1;
				sum[j]=cnt[minn[minid]];
				cnt[minn[j]]+=sum[j];
				if(sum[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
