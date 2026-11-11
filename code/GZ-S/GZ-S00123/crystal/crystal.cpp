//GZ-S00123 遵义市汇川区第二小学 韩铭钊 
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],b[500005],ans=1,c[500005],d[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
		if(i==1) b[i]=0;
	}
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+b[i];
	}
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+c[i];
	}
	for(int i=2;i<=n;i++){
		int sum=i*c[i]-d[i];
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(sum-((mid-1)*c[i]-d[mid-1])<=m){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
