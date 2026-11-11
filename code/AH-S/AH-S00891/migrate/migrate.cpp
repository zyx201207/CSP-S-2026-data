#include<bits/stdc++.h>
using namespace std;
long long n,d,c,t,x[2000005],ans,dis[2000005],f[2000005],sum[2000005],nxt[2000055];
void work(int r) {
	for(int i=1; i<=n; i++)dis[i]=1e9,f[i]=0,sum[i]=0;
	dis[r]=0;
	f[r]=sum[r]=1;
	int l=r,k=r+1;
	while(k<=n) {
		if(x[k]-x[r]>d) {
			if(k==r+1)break;
			else {
				l=r+1,r=k-1;
				continue;
			}
		} else {
			dis[k]=dis[r]+1;
			while(l<r&&x[k]-x[l]>d) {
				l++;
			}
			f[k]=sum[r]-sum[l-1];
		}
		sum[k]=sum[k-1]+f[k];
		k++;
	}
	for(int i=1; i<=n; i++) {
		if(f[i]==2)ans++;
	}
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--) {
		ans=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
		}
		if(c>=13&&c<=14) {
			for(int i=1;i<=n;i++){
				if(x[i]+d>=x[n])nxt[i]=n;
				else nxt[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;			
			}
			for(int i=1,l,r;i<=n;i++){
				if(nxt[i]-i<2)continue;
				l=nxt[nxt[i]-2]+1;
				r=nxt[nxt[i]-1];
				if(r<l)continue;
				ans+=r-l+1;
			}
			cout<<ans<<"\n";
			continue;
		}
		if(c>=11&&c<=12){
			work(1);
			for(int i=1;i<=n;i++){
				ans+=(n-i)*(f[i]==2);
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1; i<=n; i++) {
			work(i);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
