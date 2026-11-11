#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll const maxn=2e6;
ll C,T;
ll n,d;
ll a[maxn+1];
ll mxg[maxn+1];
ll f[maxn+1];
ll ds[maxn+1];
ll s[maxn+1];
ll const inf=1e18;
void sol(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[n]-a[1]<=d){
		cout<<"0\n";
		return;
	}
	a[n+1]=1e18;
	for(ll i=1,j=1;i<=n;i++){
		j=max(j,i);
		while(j<n&&a[j+1]-a[i]<=d){
			j++;
		}
		mxg[i]=j;
	}
	if(C>=11&&C<=12){
		ll all=1,arr=n;
		while(all<arr){
			ll mid=(all+arr+1)>>1;
			ll r=mid;
			s[r+1]=0;
			f[r]=1;
			ds[r]=0;
			s[r]=1;
			ll res=0;
			for(ll l=r-1;l>=1;l--){
				if(mxg[l]==l){
					break;
				}
				ds[l]=ds[min(r,mxg[l])]+1;
				ll su=0;
				{
					ll al=l,ar=min(r,mxg[l]);
					while(al<ar){
						ll mid=(al+ar+1)>>1;
						if(ds[mid]<ds[l]-1){
							ar=mid-1;
						}
						else{
							al=mid;
						}
					}
					su-=s[al+1];
				}
				{
					ll al=l,ar=min(r,mxg[l]);
					while(al<ar){
						ll mid=(al+ar)>>1;
						if(ds[mid]>=ds[l]){
							al=mid+1;
						}
						else{
							ar=mid;
						}
					}
					su+=s[al];
				}
				f[l]=min(3ll,su);
				s[l]=s[l+1]+f[l];
				if(f[l]==2){
					res++;
				}
			}
			if(res){
				arr=mid-1;
			}
			else{
				all=mid;
			}
		}
		cout<<n-arr<<"\n";
		return;
	}
	ll ans=0;
	for(ll r=1;r<=n;r++){
		s[r+1]=0;
		f[r]=1;
		ds[r]=0;
		s[r]=1;
		ll res=0;
		for(ll l=r-1;l>=1;l--){
			if(mxg[l]==l){
				break;
			}
			ds[l]=ds[min(r,mxg[l])]+1;
			ll su=0;
			{
				ll al=l,ar=min(r,mxg[l]);
				while(al<ar){
					ll mid=(al+ar+1)>>1;
					if(ds[mid]<ds[l]-1){
						ar=mid-1;
					}
					else{
						al=mid;
					}
				}
				su-=s[al+1];
			}
			{
				ll al=l,ar=min(r,mxg[l]);
				while(al<ar){
					ll mid=(al+ar)>>1;
					if(ds[mid]>=ds[l]){
						al=mid+1;
					}
					else{
						ar=mid;
					}
				}
				su+=s[al];
			}
			f[l]=min(3ll,su);
			s[l]=s[l+1]+f[l];
			if(f[l]==2){
				res++;
			}
			if(su==(mxg[l]-l)*3){
				break;
			}
		}
//		for(ll i=1;i<=n;i++){
//			cout<<ds[i]<<" ";
//		}
//		cout<<"\n";
//		for(ll i=1;i<=n;i++){
//			cout<<f[i]<<" ";
//		}
//		cout<<"\n";
		ans+=res;
//		cout<<res<<" ";
	}
	cout<<ans<<"\n";
}
/*
0 1
5 3
-3 0 2 3 4

*/
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>T;
	while(T--){
		sol();
	}
	
	
	return 0;
}
