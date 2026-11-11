#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,a[2000005],cnt,x[5005],l,y[5005],z[5005],T,d;
bool flag;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) {
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		cnt=0;
		if(n<=5000) {
			for(int i=1;i<n;i++) {
				l=i;
				for(int j=i+1;j<=n;j++) {
					while(a[j]-a[l]>d) l++;
					x[j]=x[l]+1;
				}
				l=i+1;
				for(int j=i+2;j<=n;j++) {
					while(a[j]-a[l]>d) l++;
					y[j]=y[l]+1;
				}
				l=i+2;
				for(int j=i+3;j<=n;j++) {
					while(a[j]-a[l]>d) l++;
					z[j]=z[l]+1;
				}
				flag=0;
				for(int j=i+3;j<=n;j++) if(x[i+2]+z[j]!=x[j]) flag=1;
				if(x[i+2]+z[i+3]==x[i+3]&&x[i+2]<x[i+3]) for(int j=i;j<=n;j++) z[j]=-1e18;
				for(int j=i;j<=n;j++) 
					if(x[j]==y[j]+x[i+1]&&y[j]+x[i+1]!=z[j]+x[i+2]&&x[j]>1) cnt++;
				for(int j=i;j<=n;j++)
					x[j]=y[j]=z[j]=0;
				
			}
			printf("%lld\n",cnt);
		}
		else printf("0\n");
	}
	
	return 0;
}
