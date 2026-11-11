#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MX=2e5+1;
int n,a[MX];
char c[MX];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
	}
	int p=1,q=n,ans=0;
	while(p<q){
		if(a[p]>a[q]){
			ans+=(c[p]!=c[q])*a[q];
			a[p]-=a[q];
			--q;
		}else if(a[p]<a[q]){
			ans+=(c[p]!=c[q])*a[p];
			a[q]-=a[p];
			++p;
		}else{
			ans+=(c[p]!=c[q])*a[p];
			++p;
			--q;
		}
	}
	cout<<ans;
	return 0;
}

