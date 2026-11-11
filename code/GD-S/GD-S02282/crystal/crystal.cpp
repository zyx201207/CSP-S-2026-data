#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=500005;
int a[N];
ll s[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	s[0]=0;
	for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
	int ans=0;
	for(int l=1,r=1;l<=n;l++){
		while(r<=n && 1ll*(r-l+1)*a[r]-(s[r]-s[l-1])<=m)r++;
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}
/*
5 6
2 1 0 4 6
3
*/
