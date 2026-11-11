#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans,b[500010],c[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[n]-a[i];
	}
	for(int i=n;i>=1;i--){
		c[i]=c[i+1]+b[i];
	}
	//for(int i=1;i<=n;i++) cout<<c[i]<<" ";
	for(int i=1;i<=n;i++){
		long long l=1,r=i;
		while(l<r){
			long long mid=(l+r)>>1;
			if(c[mid]-c[i]-(a[n]-a[i])*(i-mid)<=m){
				r=mid;
			}
			else {
				l=mid+1;
			}
		}
		//cout<<i<<" "<<r<<endl;
		ans=max(ans,i-r+1);
	}
	cout<<ans<<endl;
	return 0;
}
//wo *** you ducuotile
// 16:30 first 
