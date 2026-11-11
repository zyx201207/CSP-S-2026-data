#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],f[500005],l=1,ans,cnt;
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
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+b[i];
	}
	for(int r=1;r<=n;r++){
		cnt+=(r-l)*(f[r]-f[r-1]);
		while(cnt>m){
			cnt-=(f[r]-f[l]);l++;
//			cout<<cnt<<' '<<l<<' '<<r<<'\n';
		}
		ans=max(ans,(r-l+1));
		
	}
	cout<<ans; 
	return 0;
}
