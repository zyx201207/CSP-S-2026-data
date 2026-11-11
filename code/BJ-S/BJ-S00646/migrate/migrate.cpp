#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+5;
int c,t,n,d,a[N],f[N],ri[N],pl[N],js[N],ans,sum[N];
bool check(int l,int r){
	return a[r]-a[l]<=d;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
		cin>>n>>d;
		for(int i = 1;i<=n;++i)cin>>a[i];
		ans=0;
		int l,r,mid,pans,lim;
		if(c==11||c==12){
			f[1]=0,lim=2;
			for(int j = 2;j<=n&&a[j]-a[j-1]<=d;++j,++lim){
				l=1,r=j-1,pans=1;
				while(l<=r){
					mid=(l+r)>>1;
					if(check(mid,j))pans=mid,r=mid-1;
					else l=mid+1;
				}
				f[j]=f[pans]+1,pl[j]=pans;
			}
			--lim;
			ri[lim]=lim;
			for(int j = lim-1;j>=1;--j){
				ri[j]=j;
				if(f[j]==f[j+1])ri[j]=ri[j+1];
			}
			sum[1]=js[1]=1,sum[0]=0;
			for(int j = 2;j<=lim;++j){
				js[j]=sum[ri[pl[j]]]-sum[pl[j]-1];
				ans+=(js[j]==2)*(n-j+1);
				sum[j]=sum[j-1]+js[j];
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i = 1;i<=n;++i){
			f[i]=0,lim=i+1;
			for(int j = i+1;j<=n&&a[j]-a[j-1]<=d;++j,++lim){
				l=i,r=j-1,pans=i;
				while(l<=r){
					mid=(l+r)>>1;
					if(check(mid,j))pans=mid,r=mid-1;
					else l=mid+1;
				}
				f[j]=f[pans]+1,pl[j]=pans;
			}
			--lim;
			ri[lim]=lim;
			for(int j = lim-1;j>=i;--j){
				ri[j]=j;
				if(f[j]==f[j+1])ri[j]=ri[j+1];
			}
			sum[i]=js[i]=1,sum[i-1]=0;
			for(int j = i+1;j<=lim;++j){
				js[j]=sum[ri[pl[j]]]-sum[pl[j]-1];
				ans+=(js[j]==2);
				sum[j]=sum[j-1]+js[j];
			}
		}
		cout<<ans<<'\n';
	}
    return 0;
}
