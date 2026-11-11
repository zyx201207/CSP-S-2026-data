#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500009],n,s[500009],ans;
long long m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i];
		s[i]+=s[i-1];
		long long d=1LL*i*a[i]-s[i];
		if(d<=m)ans=i;
		else break;
	}
	cout<<ans;
	return 0;
}
