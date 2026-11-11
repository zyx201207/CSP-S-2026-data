#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,dk,d[500005],a[500005],f[500005],ans;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		cin>>n>>dk;
		ans=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int zx=1; zx<=n; zx++) {
			memset(f,0,sizeof(f));
			for(int i=zx; i<=n; i++) d[i]=-2;
			d[zx]=0;
			for(int i=zx; i<=n; i++) {
				for(int j=i+1; j<=n; j++) {
					if(a[j]-a[i]<=dk) {
						if(d[j]+1<d[i]) {
							d[j]=d[i]+1;
							f[j]=1;
						} else if(d[j]==d[i]+1) {
							f[j]++;
						}
					} else break;
				}
//				cout<<f[i]<<" "<<d[i]<<endl;
			}
			for(int i=zx; i<=n; i++) {
				if(f[i]==2) ans+=1;
			}

		}
		cout<<ans<<endl;

	}
	return 0;
}
//CCFwcnm
