#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n;
long long m,a[N],ans,sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=1;
	for(l=1;l<=n;l++){
		while((sum[r]-sum[l-1])+m>=a[r]*(r-l+1) && r<=n)r++;
		r--;
		ans=max(ans,1ll*r-l+1);
	}
	cout<<ans<<endl;
	return 0;
} 
