#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
long long n,m,a[N],s[N],maxx;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	} long long l=1;
	for(int i=1;i<=n;i++){
		while(l<=i-maxx) {
			int u=s[i-1]-s[l-1];
			if(a[i]*(i-l)-u<=m) {
				maxx=max(maxx,i-l+1);
				break;
			} l++;
		}
	} cout<<maxx;
	return 0;
}

