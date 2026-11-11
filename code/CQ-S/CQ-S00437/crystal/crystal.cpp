#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);a[0]=a[1];
	for(int i=1,l=1;i<=n;i++){
		m-=(i-l)*(a[i]-a[i-1]);
		while(m<0){
			m+=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1ll);
	}
	cout<<ans;
	return 0;
} 
