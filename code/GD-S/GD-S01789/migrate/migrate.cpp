#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL C,T,n,D;
LL a[2000005],f[5005],sum[5005],dis[5005];
inline void solve(){
	LL ans=0;
	cin>>n>>D;
	for(LL i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		cout<<"0"<<endl;
		return;
	}
	if(11<=C&&C<=12){
		LL tmp=a[2]-a[1];
		LL g=D/tmp;
		if(g<=1){
			cout<<"0"<<endl;
			return;
		}
		g=g*2;
		cout<<max(0ll,n-g+1)<<endl;
		return;
	}
	if(13<=C&&C<=14){
		int ans=0;
		for(int k=1;k<n;k++){
			int l=k+1,r=n;
			while(l<r){
				int mid=(l+r+1)>>1;
				if(a[mid]-a[k]<=D) l=mid;
				else r=mid-1;
			}
			int R=l;
			if(R==n) continue;
			if(R==k+1) continue;
			l=k+1,r=n;
			while(l<r){
				int mid=(l+r+1)>>1;
				if(a[mid]-a[R-1]<=D) l=mid;
				else r=mid-1;
			}
			int t1=l;
			if(k+2==R){
				ans+=t1-R;
				continue;
			}
			l=k+1,r=n;
			while(l<r){
				int mid=(l+r+1)>>1;
				if(a[mid]-a[R-2]<=D) l=mid;
				else r=mid-1;
			}
			int t2=l;
			ans+=t1-t2;
		}
		cout<<ans<<endl;
		return;
	}
	for(LL k=1;k<n;k++){
		memset(dis,-1,sizeof(dis));
		dis[k]=0;
		LL lst=k;
		do{
			LL l=lst+1,r=n;
			while(l<r){
				LL mid=(l+r+1)>>1;
				if(a[mid]-a[lst]<=D) l=mid;
				else r=mid-1;
			}
			if(a[l]-a[lst]>D) break;
			for(LL i=lst+1;i<=l;i++){
				dis[i]=dis[lst]+1;
			}
			lst=l;
		}while(lst<n);
		memset(f,0,sizeof(f));
		memset(sum,0,sizeof(sum));
		f[k]=1;
		sum[k]=1;
		for(LL i=k+1;i<=n;i++){
			LL l=1,r=i-1;
			while(l<r){
				LL mid=(l+r)>>1;
				if(a[i]-a[mid]<=D) r=mid;
				else l=mid+1;
			}
			if(a[i]-a[l]>D) break;
			LL tmp=l;
			r=i-1;
			while(l<r){
				LL mid=(l+r+1)>>1;
				if(dis[mid]<dis[i]) l=mid;
				else r=mid-1;
			}
			f[i]=sum[l]-sum[tmp-1];
			sum[i]=sum[i-1]+f[i];
			if(f[i]==2) ans++;
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--) solve();
	return 0;
}
