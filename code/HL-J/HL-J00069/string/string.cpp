#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,ans;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l]<a[r]){
			ans+=(c[l]!=c[r]?1:0)*a[l];
			a[r]-=a[l];
			l++;
		}
		else if(a[l]==a[r]){
			ans+=(c[l]!=c[r]?1:0)*a[l];
			l++,r--;
		}
		else{
			ans+=(c[l]!=c[r]?1:0)*a[r];
			a[l]-=a[r];
			r--;
		}
	}
	cout<<ans<<'\n';
	return 0;
}