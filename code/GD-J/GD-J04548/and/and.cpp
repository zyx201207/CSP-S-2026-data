#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],sum=-1;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	if(n==m){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		int ans=-1;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==3){
		int ans=-1;
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<=n;k++)
				ans=max(a[i]&a[j]&a[k],ans);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==4){
		int ans=-1;
		for(int i=1;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					for(int kk=k+1;kk<=n;kk++)ans=max(a[i]&a[j]&a[k]&a[kk],ans);
				}
				
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==5){
		int ans=-1;
		for(int i=1;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				for(int k=j+1;k<n-1;k++){
					for(int kk=k+1;kk<n;kk++)
						for(int kkk=kk+1;kkk<=n;kkk++)
							ans=max(a[i]&a[j]&a[k]&a[kk]&a[kkk],ans);
				}
				
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==6){
		int ans=-1;
		for(int i=1;i<n-4;i++){
			for(int j=i+1;j<n-3;j++){
				for(int k=j+1;k<n-2;k++){
					for(int kk=k+1;kk<n-1;kk++)
						for(int kkk=kk+1;kkk<n;kkk++)
							for(int ki=kkk+1;ki<=n;ki++)
							ans=max(a[i]&a[j]&a[k]&a[kk]&a[kkk]&a[ki],ans);
				}
				
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	sum=a[n];
	for(int i=n,hh=m;hh>=1;i--,hh--){
		sum&=a[i];
	}
		cout<<sum;
	
	return 0;
}
