#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int t,n,d,a[N],ans;
bool v[N];
int er(int x){
	int l=1,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(a[mid]<=x) l=mid;else r=mid-1;
	}return l;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;++i) cin>>a[i],v[i]=0;
		for(int i=1;i<n;++i){
			int c1=0,c2=0,x=i,yy=0,zz=0;
			for(int j=1;j<=n-i;++j){
				int xx=er(a[x]+d),y=er(a[xx]-1),z=er(a[y]-1);
				int ll=er(a[z]+d),rr=er(a[y]+d);
				int l=max(x,ll),r=max(rr,x);int tt=x;
				x=xx;
				if(yy==x){if(c1||c2) break;c1=1;}
				if(yy==y) c2=1;else c2=0;
				if(zz==y) c2=1;
				zz=max(zz,z);
				zz=er(a[zz]+d);
				yy=max(yy,y);
				yy=er(a[yy]+d);
				if(c1){
					ans+=(max(x,r)-r);
				}
				else if(!c2){
					if(y<=tt) continue;
					ans+=(r-l);//j
				}
				else break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
