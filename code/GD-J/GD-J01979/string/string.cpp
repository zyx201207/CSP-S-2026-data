#include<bits/stdc++.h>
using namespace std;
int n,t,ans,a[200005],ti=1,ba[200005];
char c,b[200005],bc[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>c;
	//	ans+=t;
		a[ti]=t;
		b[ti]=c;
		ti++;
	}
	for(int i=1;i<=n/2;i++){
		if(a[i]!=a[n-i]&&b[i]!=b[n-i]){
			ans+=min(a[i],a[n-i]);
			a[n-i]=a[i];
			b[n-i]=b[i];
		}else if(a[i]!=a[n-i]&&b[i]==b[n-i]){
			ans+=abs(a[i]-a[n-i]);
			a[n-i-1]+=abs(a[i]-a[n-i]);
			a[n-i]=a[i];
		}else if(b[i]!=b[n-i]){
			ans+=a[n-i];
		}
	}
	cout<<ans;
	return 0;
}
