#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans,r=1,pre[N],ma;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int l=1;l<=n;l++){
		while(r<=n&&m>=a[r+1]*(r-l+2)-pre[r+1]+pre[l-1])r++;
		ma=max(ma,r-l+1);
	}
	cout<<ma;
	return 0;
}
