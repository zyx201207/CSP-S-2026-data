#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],f[N];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) f[i]=(a[i]-a[i-1])*(i-1)+f[i-1];
	int l=1,r=1,ans=0;
	while(r<n){
		while(f[r]-f[l-1]-(a[r]-a[l-1])*(l-1)<=m&&r<n) r++;
		ans=max(ans,r-l);
//		cout<<l<<" "<<r<<"\n";
		while(l<r&&f[r]-f[l-1]-(a[r]-a[l-1])*(l-1)>m) l++;
	}
	cout<<ans;
	return 0;
}
