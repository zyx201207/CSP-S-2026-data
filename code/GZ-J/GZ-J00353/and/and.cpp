#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[n+10]={0};
	int s[n+10]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]&a[i];
	}
	int maxn=0;
	for(int i=m;i<=n;i++){
		if(a[i]-a[i-m]>maxn) maxn=a[i]|a[i-m];
	}
	cout<<maxn;
	return 0;
}
