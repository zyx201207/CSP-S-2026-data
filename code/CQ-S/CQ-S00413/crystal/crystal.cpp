#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std; 
int n,m,a[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1,l,r,mid;i<=n;i++){
		l=1,r=i;
		while(l<r){
			mid=(l+r)/2;
			if((a[i]*(i-mid+1)-(s[i]-s[mid-1]))<=m) r=mid;
			else l=mid+1;
		}ans=max(ans,i-r+1);
	}cout<<ans;
	return 0;
}
