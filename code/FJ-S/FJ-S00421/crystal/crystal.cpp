#include<bits/stdc++.h>
using namespace std;
long long n,ans=1,m,maxn=-1e12,a[500005],qzh[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	for(long long i=n;i>=1;i--){
	    qzh[i]=(maxn-a[i])+qzh[i+1];
	}
	for(long long i=n;i>=1;i--){
		long long l=0,r=i+1;
		while(l+1!=r){
			long long mid=(l+r)>>1;
			if(qzh[mid]-qzh[i+1]-(maxn-a[i])*(i-mid+1)<=m){
				r=mid;
			}else l=mid;
		}
		ans=max(ans,(i-r+1));
	}
	cout<<ans;
	return 0;
}
