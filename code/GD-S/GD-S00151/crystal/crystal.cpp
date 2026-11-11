#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
long long n,m,ans;
long long a[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(long long i=1,j=1;i<=n;i++){
		while(j<i&&(i-j)*a[i]-(sum[i-1]-sum[j-1])>m) j++;
		ans=max(ans,i-j+1);
	}cout<<ans;
	return 0;
} 
