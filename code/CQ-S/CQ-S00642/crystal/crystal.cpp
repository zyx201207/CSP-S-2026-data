#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int a[maxn],s[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int res=0;
	for(int l=1,r=1;r<=n;r++){
		while((r-l+1)*a[r]-(s[r]-s[l-1])>m)l++;
		res=max(res,r-l+1);
	}
	cout<<res;
	return 0;
}
