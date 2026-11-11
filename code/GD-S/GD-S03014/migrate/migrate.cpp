#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long x[2000010];
long long f[2000010];
long long cnt[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long res=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int r=2;r<=n;r++){
			memset(f,0x3f,sizeof(f));
			memset(cnt,0,sizeof(cnt));
			cnt[r]=1;
			f[r]=0;
			for(int l=r-1;l>=1;l--){
				for(int k=l+1;k<=r&&(x[k]-x[l]<=d);k++){
					f[l]=min(f[l],f[k]+1);
				}
				for(int k=l+1;k<=r&&(x[k]-x[l]<=d);k++){
					if(f[k]+1==f[l]){
						cnt[l]+=cnt[k];
					}
				}
				if(cnt[l]==2)res++;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
