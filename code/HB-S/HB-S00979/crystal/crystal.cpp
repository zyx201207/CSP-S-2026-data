#include <bits/stdc++.h>
using namespace std;
#define int long long
int s[500005],f[500005],a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+s[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=s[i]*i-a[i];
	}
	for(int i=n;i>=1;i--){
		if(f[i]<=m){
			cout<<i;
			break;
		}
	}
	
	return 0;
}
