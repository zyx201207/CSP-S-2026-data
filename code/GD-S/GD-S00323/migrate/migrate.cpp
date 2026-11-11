#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int C,T,n,d,a[N],ans,sum;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(C>=11&&C<=12){
			sum=a[2]-a[1];
		if(d<2*sum){
			cout<<0<<endl;
			continue;
		}
		d=d/sum*sum;
		for(int i=1;i<=n;i++){
			if(a[n]-a[i]<2*d-sum)break;
			ans++;
		}
		}
		else {
			for(int i=1;i<=n;i++){
				if(a[i+1]-a[i]>d){
					n=i;
					break;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[n]-a[i]<=d)break;
				int j=upper_bound(a+1,a+n+1,a[i]+d)-a;
				for(;j<=n;j++){
					bool ff=0,f=0;
					sum=(a[j]-a[i])/d;
					int num=a[i]+2*d;
					while(sum--){
						int k=upper_bound(a+1,a+j+1,num)-a-1;
						int l=lower_bound(a+1,a+k+1,a[k]-d)-a;
						int r=upper_bound(a+1,a+k+1,num-d)-a-1;
						//cout<<i<<" "<<j<<" "<<sum<<" "<<k<<" "<<l<<" "<<r<<" "<<endl;
						if(r-l>2){
							ff=1;
							break;
						}
						else if(r-l==1){
							 if(!f)f=1;
							 else {
							 	ff=1;
							 	break;
							 }
						}
						num=a[l]+d;
					}
					if(!ff&&f)ans++;
					//cout<<i<<" "<<j<<" "<<ans<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
