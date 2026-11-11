#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],p[1000005],m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+a[i];
		long long l=1,r=i-1;
		while(l<r){
			int mid=(l+r)/2;
			if((i-mid)*a[i]-p[i-1]+p[mid-1]>m) l=mid+1;
			else r=mid;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
}
