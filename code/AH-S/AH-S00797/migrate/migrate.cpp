#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000005];
int f[305],cnt[305],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			memset(f,0x3f,sizeof f);
			memset(cnt,0,sizeof cnt);
			cnt[i]=1,f[i]=0;
			for(int j=i+1;j<=n;j++){
				int k=j;
				while(k>1&&a[j]-a[--k]<=d){
					if(f[k]+1<f[j]){
						f[j]=f[k]+1;
						cnt[j]=cnt[k];
					}
					else if(f[k]+1==f[j]){
						cnt[j]+=cnt[k];
					}
				}
				if(cnt[j]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

