#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],l,r,mid,i,j,k,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
		l=1;r=i;
		mid=(l+r)/2;
		while(l<=r){
			if(a[i]*(i-mid+1)-b[i]+b[mid-1]<=m)r=mid-1;
			else l=mid+1;
			mid=(l+r)/2;
		}
		ans=max(ans,i-mid);
	}
	cout<<ans;
	return 0;
}
