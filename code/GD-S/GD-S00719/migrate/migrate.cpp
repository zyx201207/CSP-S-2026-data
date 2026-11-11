#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int n,d,ans=0;
		cin>>n>>d;
		int a[n+5]={0};
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			int pow=a[i]+d;
			int l=1,r=n;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[mid]<=pow){
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
			//cout<<T<<" "<<i<<" "<<l<<" "<<r<<"\n";
			int pow1=a[r],pow2=a[r-2]+d,pow3=a[r-1]+d;
			l=1,r=n;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[mid]<=pow3){
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
			int res1=r;
			l=1,r=n;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[mid]<=pow2){
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
			int res2=r;
			if(a[r]!=pow1&&res1!=res2){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
